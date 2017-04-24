// Agent.cpp: implementation of the SIMAgent class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Behavior.h"
#include "Agent.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//Construct static variables
//Their real values are set in static function SIMAgent::InitValues()
vector<SIMAgent*> SIMAgent::agents;
bool SIMAgent::debug = false;
float SIMAgent::radius = 20.0;
float SIMAgent::Mass = 1.0;
float SIMAgent::Inertia = 1.0;
float SIMAgent::MaxVelocity = 20.0;
float SIMAgent::MaxForce = 10.0;
float SIMAgent::MaxTorque = 40.0;
float SIMAgent::MaxAngVel = 10.0;
float SIMAgent::Kv0 = 1.0;
float SIMAgent::Kp1 = 1.0;
float SIMAgent::Kv1 = 1.0;
float SIMAgent::KArrival = 1.0;
float SIMAgent::KDeparture = 1.0;
float SIMAgent::KNoise = 1.0;
float SIMAgent::KWander = 1.0;
float SIMAgent::KAvoid = 1.0;
float SIMAgent::TAvoid = 1.0;
float SIMAgent::RNeighborhood = 1.0;
float SIMAgent::KSeparate = 1.0;
float SIMAgent::KAlign = 1.0;
float SIMAgent::KCohesion = 1.0;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
////////////////////////////////////////////////////////////////////// 
vec2 SIMAgent::WorldToLocal(vec2 &w)
{
	vec2 l;
	float s = sin(state[1]);
	float c = cos(state[1]);
	l[0] = c * w[0] + s * w[1];
	l[1] = -s * w[0] + c * w[1];
	return l;
}

vec2 SIMAgent::LocalToWorld(vec2 &l)
{
	vec2 w;
	float s = sin(state[1]);
	float c = cos(state[1]);
	w[0] = c * l[0] - s * l[1];
	w[1] = s * l[0] + c * l[1];
	return w;
}

void SIMAgent::SetVTheta(vec2 &V)
{
	vd = V.Length();
	if (vd < 0.0001) {
		thetad = 0.0;
	}
	else {
		if (abs(V[0]) < 0.0001) {
			if (V[1] > 0)
				thetad = M_PI / 2.0;
			else
				thetad = M_PI / -2.0;
		}
		else
			thetad = atan2(V[1], V[0]);
	}

	ClampAngle(thetad);
}

SIMAgent::SIMAgent()
{
}

SIMAgent::~SIMAgent()
{
}

void SIMAgent::Display()
{
	glPushMatrix();
	glTranslatef(GPos[0], rootHeight[frameNum], GPos[1]);
	if (showLeader && this == SIMAgent::agents[0]) {
		float red[] = { 1.0, 0.0, 0.0 };
		glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, red);
		glPushMatrix();
		glTranslatef(0.0, 100.0, 0.0);
		glRotatef(90.0, 1.0, 0.0, 0.0);
		glutSolidCone(10.0, 20.0, 24, 24);
		glPopMatrix();
	}

	float specular[] = { 1.0, 1.0, 1.0, 1.0 };
	glMaterialfv(GL_FRONT, GL_AMBIENT, color);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialf(GL_FRONT, GL_SHININESS, 50);

	if (SIMAgent::debug) {
		glutSolidSphere(10.0, 24, 24);
		glDisable(GL_LIGHTING);
		glPushMatrix();
		glColor3f(1.0, 0.0, 0.0);
		glRotatef(-state[1] / M_PI * 180.0, 0.0, 1.0, 0.0);
		glLineWidth(3.0);
		glBegin(GL_LINES);
		glVertex3f(0.0, 0.0, 0.0); glVertex3f(12 + state[2], 0.0, 0.0);
		glEnd();
		glPopMatrix();
		glPushMatrix();
		glColor3f(0.0, 1.0, 0.0);
		glRotatef(-thetad / M_PI * 180.0, 0.0, 1.0, 0.0);
		glLineWidth(3.0);
		glBegin(GL_LINES);
		glVertex3f(0.0, 0.0, 0.0); glVertex3f(12 + vd, 0.0, 0.0);
		glEnd();
		glPopMatrix();
		glLineWidth(1.0);
		glEnable(GL_LIGHTING);
	}
	else {
		glRotatef(90.0f - state[1] * Rad2Deg, 0.0, 1.0, 0.0);
		//glutSolidSphere(6.0f, 12, 12);
		glCallList(AgentDisplay::listNames + frameNum);
	}
	glPopMatrix();
}

void SIMAgent::ClearAgents() {
	for (unsigned int i = 0; i < agents.size(); i++)
		delete SIMAgent::agents[i];
	SIMAgent::agents.clear();
}

SIMAgent::SIMAgent(float* color, CEnvironment* env) {
	memcpy(this->color, color, sizeof(float) * 3);
	dimState = 4;
	dimInput = 2;
	frameNum = rand() % totalFrames;
	this->env = env;
	float angle = float(rand() % 360) / 180.0 * M_PI;
	vWander[0] = cos(angle) * SIMAgent::KWander;
	vWander[1] = sin(angle) * SIMAgent::KWander;
	angle = float(rand() % 360) / 180.0 * M_PI;
	v0[0] = cos(angle) * SIMAgent::MaxVelocity / 2.0;
	v0[1] = sin(angle) * SIMAgent::MaxVelocity / 2.0;
	SIMAgent::agents.push_back(this);
}

void SIMAgent::SetInitState(float pos[], float angle)
{
	int i;
	GPos[0] = pos[0];
	GPos[1] = pos[1];
	for (i = 0; i < dimState; i++) {
		state[i] = 0.0;
	}
	for (i = 0; i < dimInput; i++)
		input[i] = 0.0;
	state[1] = angle;
}

void SIMAgent::Sense(int type)
{
	showLeader = (type == LEADER);
	goal = env->goal;
	switch (type) {
	case SEEK: Seek(); break;
	case FLEE: Flee(); break;
	case ARRIVAL: Arrival(); break;
	case DEPARTURE: Departure(); break;
	case WANDER: Wander(); break;
	case AVOID: Avoid(); break;
	case SEPARATION: Separation(); break;
	case ALIGNMENT: Alignment(); break;
	case COHESION: Cohesion(); break;
	case FLOCKING: Flocking(); break;
	case LEADER: Leader(); break;
	}
}

void SIMAgent::Act(float deltaT)
{
	int dframe;
	this->deltaT = deltaT;
	FindDeriv();
	UpdateState();
	if (abs(state[2]) < 0.001)
		dframe = 0;
	else {
		dframe = int(state[2] / SIMAgent::MaxVelocity * 2 + 1);
	}
	frameNum += dframe;
	if (frameNum >= totalFrames) {
		frameNum = frameNum - totalFrames;
	}
}

void SIMAgent::SetV0()
{
	v0 = env->goal - GPos;
	v0 = v0.Normalize() * SIMAgent::MaxVelocity / 2;
}

/*
Sets the intial Values
*/
void SIMAgent::InitValues()
{
	/*********************************************
	// TODO: Add code here
	Set initial value for control and behavior settings
	You need to find out appropriate values for:
	SIMAgent::Kv0, SIMAgent::Kp1, SIMAgent::Kv1, SIMAgent::KArrival, SIMAgent::KDeparture,
	SIMAgent::KNoise, SIMAgent::KWander, SIMAgent::KAvoid, SIMAgent::TAvoid, SIMAgent::RNeighborhood,
	SIMAgent::KSeparate, SIMAgent::KAlign, SIMAgent::KCohesion.
	*********************************************/
	//Help from Alex/Sarah with regards to decreasing/increasing/manipulating initial values
	Kv0 = 10.0;
	Kp1 = -50.0; 
	Kv1 = 15.0;
	KArrival = 0.03; 
	KDeparture = 15.0;
	KNoise = 10.0;
	KWander = 8.0;
	KAvoid = 1.0;
	TAvoid = 20.0;
	RNeighborhood = 800.0;
	KSeparate = 1000.0;
	KAlign = 20.0;
	KCohesion = 0.5;
}

/*
*	You should apply the control rules given desired velocity vd and desired orientation thetad.
*/
void SIMAgent::Control() //from Piazaa
{
	Truncate(vd, -SIMAgent::MaxVelocity, SIMAgent::MaxVelocity);
	input[0] = SIMAgent::Mass * SIMAgent::Kv0 * (vd - state[2]);
	Truncate(input[0], -SIMAgent::MaxForce, SIMAgent::MaxForce);

	double dangle = AngleDiff(state[1], thetad);
	input[1] = SIMAgent::Inertia * (Kp1 * dangle - Kv1 * state[3]);
	Truncate(input[1], -SIMAgent::MaxTorque, SIMAgent::MaxTorque);
}


/*
*	Compute derivative vector given input and state vectors
*  This function sets derive vector to appropriate values after being called
*/
void SIMAgent::FindDeriv()
{
	/*********************************************
	// TODO: Add code here
	*********************************************/
	//Completed with help from Sarah; found in Agent.h file
	deriv[0] = state[2];
	deriv[1] = state[3]; //velocity
	deriv[2] = input[0] / Mass;
	deriv[3] = input[1] / Inertia;// -state[3]; //Alex helped with this
}

/*
*	Update the state vector given derivative vector
*  Compute global position and store it in GPos
*  Perform validation check to make sure all values are within MAX values
*/
void SIMAgent::UpdateState() //from Piazaa
{
	for (int i = 0; i < dimState; i++) {
		state[i] += deriv[i] * deltaT;
	}
	state[0] = 0.0;

	ClampAngle(state[1]);//help from Keith to reformat this line
	Truncate(state[2], -SIMAgent::MaxVelocity, SIMAgent::MaxVelocity);

	vec2 GVelocity;
	GVelocity[0] = state[2] * cos(state[1]);
	GVelocity[1] = state[2] * sin(state[1]);
	GPos += GVelocity;

	Truncate(GPos[0], -1.0 * env->groundSize, env->groundSize);
	Truncate(GPos[1], -1.0 * env->groundSize, env->groundSize);

	Truncate(state[3], -SIMAgent::MaxAngVel, SIMAgent::MaxAngVel);
}

/*
*	Seek behavior
*  Global goal position is in goal
*  Agent's global position is in GPos
*  You need to compute the desired velocity and desired orientation
*  Store them into vd and thetad respectively
*  return a vec2 that represents the goal velocity with its direction being thetad and its norm being vd
*/
vec2 SIMAgent::Seek()
{
	/*********************************************
	// TODO: Add code here
	*********************************************/
	//From notes in class; Sarah helped identify issues and reformat the Seek function, and Alex helped with Kp arrival values
	vec2 tmp;
	tmp = goal - GPos;
	vd = SIMAgent::MaxVelocity;

	thetad = atan2(tmp[1], tmp[0]);

	return vec2(cos(thetad)*vd, sin(thetad) * vd); //Alex helped with simplification/reformating of above code


	/*tmp.Normalize();
	thetad = atan2(tmp[1], tmp[0]);
	thetad = thetad + M_PI;
	float vd = SIMAgent::MaxVelocity;
	tmp = vec2((cos(thetad)*vd), (sin(thetad)*vd));
	return tmp;
	*/
}

/*
*	Flee behavior
*  Global goal position is in goal
*  Agent's global position is in GPos
*  You need to compute the desired velocity and desired orientation
*  Store them into vd and thetad respectively
*  return a vec2 that represents the goal velocity with its direction being thetad and its norm being vd
*/
vec2 SIMAgent::Flee()
{
	/*********************************************
	// TODO: Add code here
	*********************************************/
	//From notes in class; Sarah helped reformat
	vec2 tmp;
	tmp = goal - GPos;
	tmp.Normalize();
	thetad = atan2(tmp[1], tmp[0]) + M_PI; //Alex helped with inverting this
	float vd = SIMAgent::MaxVelocity;
	tmp = vec2((cos(thetad)*vd), sin(thetad)*vd);
	return tmp;
}

/*
*	Arrival behavior
*  Global goal position is in goal
*  Agent's global position is in GPos
*  Arrival setting is in SIMAgent::KArrival
*  You need to compute the desired velocity and desired orientation
*  Store them into vd and thetad respectively
*  return a vec2 that represents the goal velocity with its direction being thetad and its norm being vd
*/
vec2 SIMAgent::Arrival()
{
	/*********************************************
	// TODO: Add code here
	*********************************************/
	//From notes in class; Sarah helped reformat this function
	vec2 tmp;
	tmp = goal - GPos;

	vd = tmp.Length()*KArrival;

	Truncate(vd, 0, SIMAgent::MaxVelocity);//Alex helped with reformating/simplifying this function, and adding Truncate
	tmp.Normalize();
	thetad = atan2(tmp[1], tmp[0]);

	return vec2(cos(thetad)* vd, sin(thetad) * vd);

	/*double dist = tmp.Length();
	vd = tmp.Length() * KArrival;
	thetad = atan2(tmp[1], tmp[0]);
	thetad += M_PI;

	if (dist > 0.0)
	{
		return vec2((cos(thetad)*vd), (sin(thetad)*vd));
	}

	float M = SIMAgent::KArrival;
	float vn = (M * vd / radius);
	return (vec2((cos(thetad)*vn), sin(thetad)*vn));
	return tmp;
	*/

}

/*
*	Departure behavior
*  Global goal position is in goal
*  Agent's global position is in GPos
*  Departure setting is in KDeparture
*  You need to compute the desired velocity and desired orientation
*  Store them into vd and thetad respectively
*  return a vec2 that represents the goal velocity with its direction being thetad and its norm being vd
*/
vec2 SIMAgent::Departure()
{
	/*********************************************
	// TODO: Add code here
	*********************************************/
	//Sarah helped with this function; explained it was very similar to arrival function
	vec2 tmp;
	tmp = goal - GPos;
	double dist = tmp.Length();
	vd = tmp.Length() * KDeparture;
	thetad = atan2(tmp[1], tmp[0]);
	thetad += M_PI;

	if (dist > 0.0)
	{
		return vec2((cos(thetad)*vd), (sin(thetad)*vd));
	}

	float M = SIMAgent::KDeparture;
	float vn = (M * vd / radius);
	return (vec2((cos(thetad)*vn), sin(thetad)*vn));
	return tmp;
}

/*
*	Wander behavior
*  VWander is in vWander
*  V0(nominal velocity) is in v0
*  Wander setting is in KWander
*  You need to compute the desired velocity and desired orientation
*  Store them into vd and thetad respectively
*  return a vec2 that represents the goal velocity with its direction being thetad and its norm being vd
*/
vec2 SIMAgent::Wander()
{
	/*********************************************
	// TODO: Add code here
	*********************************************/
	//ALex helped with this code; explained random number generator for angles and showed where to find equations on webcourses; helped fix formating errors
	vec2 tmp;
	float angle = float(rand() % 360) / 180.0 * M_PI;
	thetad = angle;
	vd = SIMAgent::MaxVelocity;

	tmp = vec2((cos(thetad)*vd)*KNoise, sin(thetad)*vd*KNoise)*KWander; //Sarah
	return tmp;
}

/*
*	Avoid behavior
*  Obstacles are in env->obstacles
*  Number of obstacles is env->obstaclesNum
*  env->obstacles[i][0] and env->obstacles[i][1] are the global position of the ith obstacle
*  env->obstacles[i][2] is the radius of the ith obstacle
*  Agent bounding sphere radius is in SIMAgent::radius
*  Avoidance settings are in SIMAgent::TAvoid and SIMAgent::KAvoid
*  You need to compute the desired velocity and desired orientation
*  Store them into vd and thetad respectively
*  return a vec2 that represents the goal velocity with its direction being thetad and its norm being vd
*/
vec2 SIMAgent::Avoid()
{
	/*********************************************
	// TODO: Add code here
	*********************************************/
	vec2 tmp;
	
	return tmp;
}

/*
*	Separation behavior
*  SIMAgent::agents[i] gives the pointer to the ith agent in the environment
*  Separation settings are in SIMAgent::RNeighborhood and SIMAgent::KSeperate
*  You need to compute the desired velocity and desired orientation
*  Store them into vd and thetad respectively
*  return a vec2 that represents the goal velocity with its direction being thetad and its norm being vd
*/
vec2 SIMAgent::Separation()
{
	/*********************************************
	// TODO: Add code here
	*********************************************/
	//help from Keith and Roberto constructing this

	vec2 tmp;
	vec2 agentsV = vec2(0.0, 0.0);
	float agentX = 0.0;
	float agentY = 0.0;
	vec2 agentPosVec;
	vec2 VelSeparate;

	for (int i = 0; i < agents.size(); i++)
	{
		agentX = GPos[0] - agents[i]->GPos[0];
		agentY = GPos[1] - agents[i]->GPos[1];
		agentPosVec = vec2(agentX, agentY);

		if (((agentX != 0.0) || (agentY != -.0)) && (agentPosVec.Length() < RNeighborhood))
		{
			agentsV[0] += (agentX / (agentPosVec.Length() * agentPosVec.Length()));
			agentsV[1] += (agentY / (agentPosVec.Length() * agentPosVec.Length()));

		}

	}

	VelSeparate = KSeparate * agentsV;

	thetad = atan2(VelSeparate[1], VelSeparate[0]);

	vd = VelSeparate.Length();

	tmp = vec2((cos(thetad) * vd), (sin(thetad) * vd));

	//vec2 sum = vec2(0, 0);

	/*for (int i = 0; i < agents.size(); i++)
	{
		vec2 distance = agents[i]->GPos - GPos;

		if (distance[0] == 0 && distance[1] == 0)
		{
			continue;
		}
		/*else
		{
			GPos[0] - agents.insert[0]->GPos[0], GPos[1] - agents.insert[1]->GPos[1];
			vec2 distance2 = GPos[0] - agents.insert[0]->GPos[0], GPos[1] - agents.insert[1]->GPos[1];
			distance2.Normalize();
		}
		*/
	return tmp;

}
	
	


/*
*	Alignment behavior
*  SIMAgent::agents[i] gives the pointer to the ith agent in the environment
*  Alignment settings are in SIMAgent::RNeighborhood and SIMAgent::KAlign
*  You need to compute the desired velocity and desired orientation
*  Store them into vd and thetad respectively
*  return a vec2 that represents the goal velocity with its direction being thetad and its norm being vd
*/
vec2 SIMAgent::Alignment()
{
	/*********************************************
	// TODO: Add code here
	*********************************************/
	//help from Roberto
	vec2 tmp;
	vec2 agentsV = Arrival();
	float agentX = 0.0;
	float agentY = 0.0;
	float agentNum = 0.0;
	vec2 agentPosVec;
	vec2 VelAlignment;
	vec2 normAgentV;


	for (int i = 0; i < agents.size(); i++)
	{
		agentX = GPos[0] - agents[i]->GPos[0];
		agentY = GPos[1] - agents[i]->GPos[1];
		agentPosVec = vec2(agentX, agentY);

		if (((agentX != 0.0) || (agentY != -.0)) && (agentPosVec.Length() < RNeighborhood))
		{
			agentsV[0] += cos(agents[i]->state[1]) * agents[i]->state[2];
			agentsV[1] += sin(agents[i]->state[1]) * agents[i]->state[2];

			normAgentV += agentsV.Normalize();

			agentNum += 1;
		}

	}

	VelAlignment = (KAlign * normAgentV);
	
	thetad = atan2(VelAlignment[1], VelAlignment[0]);

	vd = VelAlignment.Length();

	tmp = vec2((cos(thetad) * vd), (sin(thetad) * vd));

	return tmp;
}

/*
*	Cohesion behavior
*  SIMAgent::agents[i] gives the pointer to the ith agent in the environment
*  Cohesion settings are in SIMAgent::RNeighborhood and SIMAgent::KCohesion
*  You need to compute the desired velocity and desired orientation
*  Store them into vd and thetad respectively
*  return a vec2 that represents the goal velocity with its direction being thetad and its norm being vd
*/
vec2 SIMAgent::Cohesion()
{
	/*********************************************
	// TODO: Add code here
	*********************************************/
	//Roberto helped with formation of this function
	vec2 tmp;
	vec2 agentsV = vec2(0.0, 0.0);
	float agentX = 0.0;
	float agentY = 0.0;
	vec2 agentPosVec;
	vec2 VCohesion;
	float agentNum = 0.0;

	for (int i = 0; i < agents.size(); i++)
	{
		agentX = GPos[0] - agents[i]->GPos[0];
		agentY = GPos[1] - agents[i]->GPos[1];
		agentPosVec = vec2(agentX, agentY);

		if (agentPosVec.Length() < RNeighborhood)
		{
			agentsV[0] += GPos[0] - agents[i]->GPos[0];
			agentsV[1] += GPos[1] - agents[i]->GPos[1];

			agentNum += 1;
		}

	}

	VCohesion = KCohesion * ((agentsV / agents.size()) - GPos); //maybe change agentNum to agents.size()
	thetad = atan2(VCohesion[1], VCohesion[0]);
	
	vd = VCohesion.Length();

	tmp = vec2((cos(thetad) * vd), (sin(thetad) * vd));

	return tmp;
}

/*
*	Flocking behavior-
*  Utilize the Separation, Cohesion and Alignment behaviors to determine the desired velocity vector
*  You need to compute the desired velocity and desired orientation
*  Store them into vd and thetad respectively
*  return a vec2 that represents the goal velocity with its direction being thetad and its norm being vd
*/
//Roberto helped with this function
vec2 SIMAgent::Flocking()
{
	/*********************************************
	// TODO: Add code here
	*********************************************/
	vec2 tmp;
	vec2 vFlock;

	vFlock = KSeparate * Separation() + KCohesion * Cohesion() + KAlign * Alignment();
	thetad = atan2(vFlock[1], vFlock[0]);
	
	vd = vFlock.Length();

	tmp = vec2((cos(thetad) * vd), (sin(thetad) * vd));

	return tmp;
}

/*
*	Leader behavior
*  Utilize the Separation, Arrival behaviors to determine the desired velocity vector
*  You need to find the leader, who is always the first agent in SIMAgent::agents
*  You need to compute the desired velocity and desired orientation
*  Store them into vd and thetad respectively
*  return a vec2 that represents the goal velocity with its direction being thetad and its norm being vd
*/
vec2 SIMAgent::Leader()
{
	/*********************************************
	// TODO: Add code here
	*********************************************/
	//Robert helped with this function
	vec2 tmp;
	vec2 vLeader;

	vLeader = KSeparate * Separation() + KArrival * Arrival();

	thetad = atan2(vLeader[1], vLeader[0]);

	vd = vLeader.Length();

	tmp = vec2((cos(thetad) * vd), (sin(thetad) * vd));

	return tmp;
}