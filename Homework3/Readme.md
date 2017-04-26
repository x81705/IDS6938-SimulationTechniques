# Charlie Timm


# Homework 3 : Agent Based Simulation Assignment 

## IDS6938-Simulation Techniques - [University of Central Florida](http://www.ist.ucf.edu/grad/)

[University of Central Florida](http://www.ist.ucf.edu/grad/)
This is the framework for homework #3. 

The assignment is due: **Tuesday, April  25 at 11:59PM (EST)**
With Final Alibi, due date is: **Wednesday, April 26 at 11:59PM (EST)**
Total Alibi Days Used (prior to this project): **2**

### Part 1: Behaviors

**(a) - 10 points** : Compute derivative vector given input and state vectors. Implement the function *SIMAgent::FindDeriv()*. This function sets derive vector to appropriate values after being called.

Description of agent state vector and input vector:  
* state[0] is the position of the agent in local body coordinates (almost useless in this project);  
* state[1] is the orientation angle of the agent with respect to world (i.e. global) coordinates;  
* state[2] is the velocity of the agent  in local body coordinates.  
* state[3] is the angular velocity of the agent in world coordinates. 
* input[0] is the force in local body coordinates;  
* input[1] is the torque in local body coordinates

You will need to set deriv[0], deriv[1], deriv[2], deriv[3]. Compute derivative vector given input and state vectors. This function sets derive vector to appropriate values after being called. 
* deriv[2] is the velocity of the agent  in local body coordinates
* deriv[3] is the angular velocity of the agent in world coordinates
* deriv[0] is the force in local body coordinates divided by the mass.
* deriv[1] is the torque in local body coordinates divided by the inertia.

You also must implement *SIMAgent::InitValues()*: Try to figure out appropriate values for control and behavior settings. You need to find out appropriate values for: *SIMAgent::Kv0, SIMAgent::Kp1, SIMAgent::Kv1, SIMAgent::KArrival, SIMAgent::KDeparture,
SIMAgent::KNoise,	SIMAgent::KWander, SIMAgent::KAvoid, SIMAgent::TAvoid, SIMAgent::RNeighborhood, SIMAgent::KSeparate, SIMAgent::KAlign, SIMAgent::KCohesion.*

~~~
ANS: See Visual Studio file for all behavior/function coding.
~~~

**(b) - 20 points**: In this part of the assignment you will need to implement 6 types of individual behaviors and 5 types of group behaviors. Create the following behaviors through appropriate computation of V<sub> d</sub>  and θ<sub>d</sub>  commands:
* Seek
* Flee
* Arrival
* Departure
* Wander
* Obstacle Avoidance

~~~
ANS: See Visual Studio file for all behavior/function coding.
~~~

**(c) - 20 points**: Implement the functions for the following group behaviors: 
* Seperation
* Cohesion 
* Alignment 
* Flocking
* Leader Following
* 
~~~
ANS: See Visual Studio for all behavior/function coding.
~~~

~~~
References

Almodovar, Alex. Multiple conversations 
(both in-person and via email/text) 
regarding assignment, 10APR-26APR17. 
Alex provided help with reformatting
my functions for part B, and catching
syntax/logic errors within the functions.
All help received from Alex is document in 
visual studio files.

Cabrera, Roberto.  Face to face conversation
on 24APR17.  Roberto helped me with part C,
and helped me to understand how to input/translate
the code from webcourses into C++.  All help
received from Roberto is documented in visual
studio files.

MacArthur, Keith.  Face to face conversation
on 24APR17.  Keith helped me to understand
the process of coding the separation function.
All help received from Keith is documented 
in visual studio files.

Matthews, Sarah. Multiple face to face/digital 
conversations from 10APR-26APR17. For Part I, 
Sarahm helped me with multiple function 
syntax/formatting, derivative computation,
and initial value manipulation.  
All help received from Sarah is 
documented in visual studio files.
~~~

# Part 2 - Simulating A Simple Pedestrian Flow

**(a) - 0 points**: Follow the Anylogic example for the [Subway Entrance example]

~~~
ANS: I completed the tutorials with no major 
issues (screenshot included below; did not 
include 3D models (will be reflected in part 2B)).
~~~
## Subway Entrance Model/Simulation 
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework3/images/2a1.PNG?raw=true)


**(b) - 20 points**: Create a maze. Generate the pdm, stats, and animations like before. Vary [parameters in your agents](https://help.anylogic.com/index.jsp?topic=/com.xj.anylogic.help/html/_PL/reference/Attributes.html) to give them different behaviors and show the pedistrians change how they navigate the maze.

~~~
ANS: 
INTRODUCTION/ASSUMPTIONS/INIITAL CONDITIONS
This maze would replicate something similar 
to mazes commonly found in amusement parks 
around the globe.  There are two areas in 
which the agents can "see" dead ends and do 
not choose this path (see screenshot below); 
we are making the assumption that this maze 
is conducted in a medium light levels, and 
that agents will be able to generally see 
the path in front of them.  We will also 
assume that due to the difficulty of the 
maze, that after choosing a wrong path, 
agents will be redirected back to the 
decision point, and will then have an 
equal probability of choosing all paths.

Additionally, we will assume that this 
maze will replicate peak hours, with 5 
agents arriving per minute (additionally,
initial speed of .3 to .7 meters per 
second distributed uniformly, and a 
comfortable speed of 1 to 2 meters per 
second distributed unifromly, with no 
limit on agent number; will assume that 
the maze is very popular and that it is 
a weekend/federal holiday where the 
maximum traffic will occur). 

CONSTRUCTION OF THE MAZE
I first searched via google for an 
image of a maze, and then imported it to 
AnyLogic (maze obtained from MIT.edu; 
see references below).  During initial 
probelm solving, I constructed the maze 
and populated it with agents, but realized 
that the agents were simply taking the path
of least resistance to the exit, and not 
taking any dead-end turns.  I posted a 
question via Piazaa regarding this issue,
and saw that other students had used the 
pedSelect node to work around this problem 
(MacArthur, Keith; see references below). 
I utilized this method of emplacing multiple 
pedSelect nodes (linked to target lines) to 
simulate agents choosing a path based 
on equal probability.   
~~~

## Initial Conditions/Maze Model 
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework3/images/3b8.PNG?raw=true)

~~~
METHODOLOGY
To analyze the data and display stats, 
I added a pedestrian density map 
(which displays density of pedestrians 
in the simulated space via color 
representation, with blue being least 
dense and red being most dense), and 
also added timeplots for both traffic 
and intensity, in which traffic is the
number of pedestrians crossing the ped 
flow statistics lines in an hour (model time), 
and intensity is defined as the traffic
divided by the line length.  Both timeplots 
utilize one sample per second and display 
the totality of the data for 
each trial (3600 seconds).

I initially populated the maze with 
5 agents per minute (leaving all other
settings at default) and then ran the simulation
ten times and recording the number of agents 
that exited the maze.

I then took screenshots every 1200 seconds 
(or every 20 minutes (+- 5 seconds), model
time) to analyze the data, and ran the simulation 
ten times.  The screenshots below show the coalated
data for each trial, with the intensity and 
traffic timeplots at the completion of 
each individual simulation.  The traffic 
density maps represent data from left to 
right at 1200, 2400, and the 3600 
second model time.
~~~

## Simulation 1 
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework3/images/trial1.PNG?raw=true)

## Simulation 2 
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework3/images/trial2.PNG?raw=true)

## Simulation 3 
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework3/images/trial3.PNG?raw=true)

## Simulation 4 
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework3/images/trial4.PNG?raw=true)

## Simulation 5 
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework3/images/trial5.PNG?raw=true)

## Simulation 6 
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework3/images/trial6.PNG?raw=true)

## Simulation 7 
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework3/images/trial7.PNG?raw=true)

## Simulation 8 
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework3/images/trial8.PNG?raw=true)

## Simulation 9 
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework3/images/trial9.PNG?raw=true)

## Simulation 10 
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework3/images/trial10.PNG?raw=true)

~~~
ANALYSIS - Pedestrian Density Maps
To better understand the data, I then 
compared the pedestrian density maps 
at the 1200, 2400, and 3600 second marks
to analyze the data and find commonalities
in the data.  For the 1200 second dataset,
I found that the areas in vicinity target 
line 2 (with 6 instances of orange/red 
coloration) and target line 3 (with 4 
instances of orange/red coloration) had 
the greatest density.  For the 2400 second 
dataset, I found that the area in vicinity 
of target line 7 had the most density 
(10 instances of orange/red coloration) 
and target line 2 had significant density 
as well (9 instances of orange/red coloration).  
For the 3600 second dtaaset, I found that
target line 7 again had the most density 
(8 instances of red/orange coloration) 
and that target line 2 had significant 
density as well (5 instances of red/orange 
coloration).  

Taking this data, the areas of highest
pedestrian density based off the heat maps
are the target line 2, target line 3, and
target line 7 (see screenshot below).  
Through this data, we can predict where 
people will be at a certain time given 
the initial conditions, and also potentially 
reconstruct the maze (i.e., potentially 
wider walls in the areas to facilitate 
traffic flow and lessen density).  This 
data is also useful in the event of an 
emergency, as we can focus our efforts 
on sending emergency personnel to the 
areas of highest density, and essentially 
create an algorithm to save the maximum 
number of lives.
~~~

## Pedestrian Density Map - 1200 Seconds 
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework3/images/heatdensity1.PNG?raw=true)

## Pedestrian Density Map - 2400 Seconds 
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework3/images/heatdensity2.PNG?raw=true)

## Pedestrian Density Map - 3600 Seconds 
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework3/images/heatdensity3.PNG?raw=true)

## Pedestrian Density Map - All Data 
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework3/images/heatdensity4.PNG?raw=true)

~~~
ANALYSIS - Traffic Intensity Timeplots
I also coalated the data for the intensity 
timeplots.  In 80% of the samples, the 
yellow, red, and green target lines 
(target lines 2, 1, and 3) consistently 
displayed the highest traffic intensity
over time (see screenshots below).  

This data could also be used in an
algorithm to predict where pedestrians 
will be given a certain time, and also 
could be used to assist emergency personnel
in the event of an evacuation.  This 
could also be used to predict wear/tear 
on the maze itself, and potentially be 
utilized to construct a maintenance schedule.
~~~

## Intensity Timeplot- All Data 
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework3/images/intensity.PNG?raw=true)

## Areas of Highest Intensity 
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework3/images/intensity2.PNG?raw=true)

~~~
ANALYSIS - Traffic Timeplot
Similar to the intensity timeplots, 
I also coalated the data for the traffic 
timeplots.  In the majority of the data, 
target line 2 was the most prominent 
throughout the hour long simulation, 
which makes sense because the agents 
will continue to flow through the first
part of the maze.  Also, the maze was 
set up to have equal probabilities after 
each wrong path decision, and this juncture 
in the maze represents a path to other wrong 
paths within the first ped select node.  
Additionally, I observed that as time goes on, 
target line 7 (later in the maze) becomes 
more prominent in the data, which again makes 
sense due to the flow of the agents over time. 
Other commonalities between the charts 
indicated that target line 1 and target 
line 3 experienced high volumes of traffic
that generally maintained levels throughout 
the simulation, but did decrease over 
time (see screenshots below).
~~~

## Traffic Timeplot- All Data 
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework3/images/traffic1.PNG?raw=true)

## Areas of Highest Traffic
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework3/images/traffic2.PNG?raw=true)

~~~
FINAL ANALYSIS INITIAL CONDITIONS
This data, used in concert with the 
data above, is simply another way 
for the maze operators to predict 
where people will be, and at what 
roughly what time they will be there. 
This can again be used for maintenance 
purposes and emergency situations.  
Based on the intensity, density, and
traffic data, the areas that management
should focus on are the areas in 
vicinity of target 
lines 2, 3, 7 (see screenshot below).

Additionally, one of the other big 
takeaways from this was the average (mean) 
total number of agents/customers that 
made it through the maze after ten 
simulations, which I calculated to be 
244.7 agents will finish the maze within 
an hour (summed each trial (263, 248, 222,
 254, 248, 239, 261, 242, 238, 232) and 
 then divided by 10), and that 290.3 will 
 enter the maze within an hour (summed 
each trial (317, 295, 274, 299, 292, 
287, 300, 292, 276, 271) and then 
divided by 10).  This number could
be used to calculate the number 
of employees needed to properly 
man the amusement park, and could 
also be used to project customer 
throughput/flow through the maze.
~~~

## Managment Overall Focus
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework3/images/overall.PNG?raw=true)

~~~
PARAMETER CHANGE 1 & ANALYSIS
To change the parameters, I varied 
the initial speed of .3 to .7 meters 
per second (uniformly distributed) to 
1 to 1.25 meters per second, as I feel 
that in the beginning of the maze the 
rate would be increased due to lack of 
path choices for this specific maze; I 
then decreased the comfortable rate from
1 to 2 meters per second (uniformly 
distributed) to .5 to 1 meter per second,
with consideration that the maze 
operators might want to decrease the 
light levels from medium to low, 
thus increasing the difficulty 
of the maze.

-After changing this parameter, 
it is apparent that the density graph
has more intensity throughout the 
simulation, and it also appears 
that the T2L is not as prominently
featured in regards to traffic/intensity
(see screenshot below), and that there
is much more skew towards the latter
parts of the maze, specifically around
target line 7 and the hall adjacent
to target line 8, and area near
target line 9/10 (see screenshot).  
The intensity/traffic timeplots below
mirror these observations.  This 
illustrates that by simply changing 
the parameters in how the agents move,
that there could potentially be a
different maintenance focus and 
different evacuation procedures/protocol
depending on the accuracy of both models.
~~~

## Parameter Change 1 - Pedestrian Rate of Speed 
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework3/images/paramterchange1.PNG?raw=true)

## Parameter Change 1 - Areas of Focus
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework3/images/paramterchange2.PNG?raw=true)

~~~
PARAMETER CHANGE 2 & ANALYSIS
Additionally, with  I added groups 
within the simulation as often times 
many people will go to social activities
such as this with friends (initial 
conditions for group as follows: 
put a group size between 1-2 with 
uniform discreet distribution, set 
the interarrival time to within 1 
second to simulate group arriving 
together, and put the group formation
as front, as there is often one
person leading the group).

-After trying this, at approximately
362 seconds into the simulation, there
began to form pockets of agents that 
would group, presumably stuck in 
various locations in the maze; this
indicates that the maze was not
constructed for large groups, and that
potentially the creators of the maze 
should consider widening the walls to
avoid potential fire hazard/emergency
evacuation issues.  Another solution
is to have an attendant simply spacing
individuals approximately 10-15 seconds
apart to decrease the occurrence of
traffic jams.  Bottom line, this simuation
has identified a problem that if caught during
the design/development phase, could
ultimately save the maze operators
a significant amount of money, effort,
and potentially decrease hazardous
conditions.
~~~

Please use this YouTube link to view the simulation during initial conditions:
[Maze Simulation - Initial Conditions](https://youtu.be/67eFfUL0SD4)

Please use this YouTube link to view the simulation with changed parameters (both increased rate of speed and groups):
[Maze Simulation - Changed Parameters](https://youtu.be/LJ8en4xgwvg)


**(c) - 30 points**: Model and analyze a building (or floor/outdoor space/stadium) on campus. (There is help on piazza how to find rough building plans - we expect something plausible). Create a senario: evacuation, daily office routine, special event, normal egress.... etc., and model and design your own experiment to determine if the building design suits the needs of its users. Start with photographs of your site, describe your site, describe your senario and hypothesis. Then use an agent-based pedistrian simulation to visualize your experiment's results.

~~~
CONSTRUCTION/INITIAL CONDITIONS/FIRE EVACUATION SCENARIO
ANS: I first obtained digital photgraphs 
of the floor plan of the Partnership II's
first floor.  I also walked through the 
first floor and the perimeter of the 
building to confirm all office 
locations/exits.  I then imported the 
image files to AnyLogic, and began 
to trace the floor plan.

After creating the floor plan for 
the first floor, I then demarcated 
different areas where people will be 
working based on number of offices 
and generally anecdotal observations
during my time at UCF, and set the 
probability equally for agents 
using a pedSelect node with equal 
distributions of the agents going 
to one of five areas (see screenshot).
I also emplaced attractors in the 
area to ensure that the agents would
go in the vicinity of the areas 
of higher pedestrian traffic.

For the initial conditions, I left
the agents at default speeds 
(.5 to 1 uniformly distributed for 
comfotable speed, and .3 to .7 
uniformly distributed for initial speed),
placed the number of arrivals at 10 
per minute, and limited the arrivals 
to 60 (again, based on anecdotal 
evidence on how many people I 
have seen in the first floor 
during visits).  There will be 
60 agents at the time of the scenario 
start, with no additional agents 
arriving during the evacuation.

My scenario revolves around an early
morning fire that begins in the 
robotics lab; as such this exit will
be blocked, and agents will have 
to utilize exits to make it to 
designated safe zones, which I 
designated all personnel in 
areas 1, 3, and 4 to utilize Safe Area 1,
and those agents working in area 2 to
utilize Safe Area 2 (assume both are 400'
away as specified by the UCF Fireplan, 
see references).  The fire will begin 
(and simultaneously a fire alarm will sound) 
at 10 minutes in model time (I created an 
event utilized the free function to 
send the agents to the safe aeras; 
Keith helped me with calling function,
see references below).  I have inputted 
ped flow statistics throughout the 
building and in front of every exit
to measure the flow, traffic, intensity,
and density of the simulation 
(see screenshot below).

Although the UCF Fire Plan states
that less than 5-10 minutes would 
be rated excellent for a fire drill
(a "prompt and orderly evacuation"), 
in an actual fire depending on a 
multitude of variables, smoke inhalation
can quickly incapacitate individuals 
within a few minutes (Kulig, 2008).  
Therefore, in an effort to measure 
a worst case scenario, I will assume 
the fire is extremely deadly and  
will measure exit rates at 2, 3, 
and 4 minutes (+/- 5 seconds) after 
the fire alarm sounds and assume 
that any agents left within the 
building after the 4 minute mark 
will be casualties that must be
attended to by emergency personnel.
~~~

## Fire Evacuation - Model
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework3/images/fire1.PNG?raw=true)

~~~
ANALYSIS
I took screenshots of the pedestrian 
traffic at approximately 595 seconds, 
720 seconds, 780 seconds, and 840 seconds, 
and ran the simulation ten times 
(+/- 5 seconds for each screenshot).  
I also captured data via traffic and 
intensity timeplots (1 sample per 
second for 900 samples for all ped statistcs
as indicated in the model above; due to
the nature of the scenario, I stopped
collecting data after the 15 minute mark
in model time (or 5 minutes after the
evacuation)).  Please see the screenshots
below for each separate dataset.  These 
datasets are followed by coalated datasets
of each density map, and both intensity
and traffic plots.
~~~

## Fire Evacuation - Simulation 1
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework3/images/firetrial1.PNG?raw=true)

## Fire Evacuation - Simulation 2
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework3/images/firetrial2.PNG?raw=true)

## Fire Evacuation - Simulation 3
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework3/images/firetrial3.PNG?raw=true)

## Fire Evacuation - Simulation 4
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework3/images/firetrial4.PNG?raw=true)

## Fire Evacuation - Simulation 5
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework3/images/firetrial5.PNG?raw=true)

## Fire Evacuation - Simulation 6
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework3/images/firetrial6.PNG?raw=true)

## Fire Evacuation - Simulation 7
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework3/images/firetrial7.PNG?raw=true)

## Fire Evacuation - Simulation 8
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework3/images/firetrial8.PNG?raw=true)

## Fire Evacuation - Simulation 9
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework3/images/firetrial9.PNG?raw=true)

## Fire Evacuation - Simulation 10
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework3/images/firetrial10.PNG?raw=true)

~~~
ANALYSIS - Pedestrian Density Maps
Displayed below are the pedestrian 
density maps at 595 seconds (prior to 
the fier occurring), at 660 seconds 
(one minute after alarms sounds), at 
720 seconds (two minutes after), 780 
seconds (three minutes after), and at
840 seconds (four minutes after).  
Again, after the four minute mark, 
I will consider all personnel within 
the building to be casualties that 
can only be evacuated via emergency personnel.  

At 595 seconds, it is apparent
that the agents are simply settled
in their work areas.  As would be 
expected, hallway 1 and 2 have high 
density in all of the charts just 
prior to the fire, and the agents 
are fairly evenly distributed, but 
areas 2 and four have a larger 
density/number of workers 
(see screenshot below).
~~~

## Fire Evacuation - Simulation Density Map Data (595 Seconds)
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework3/images/firedensity1.PNG?raw=true)

## Fire Evacuation - Focus (595 Seconds)
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework3/images/fire595.PNG?raw=true)

~~~
At the 660 second mark, there
is an increased density in hallway 1,
and also high densities in vicinity 
of exit 5 and 1 (see screenshots below).
There is also a greater density seen
in vicinity of exit 4.  This makes
sense and likely replicates reality,
as the most convenient exits to get
to safe zone 1 are located at the
front of the building and side 
(making hallway 1 the most viable path),
with less agents leaving through the
back to safe zone 2 (see screenshots below).
Additionally, there is a mean of 23.1 agent
exits, where an exit is defined as making
it to either safe zone.
~~~

## Fire Evacuation - Simulation Density Map Data (660 Seconds)
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework3/images/firedensity2.PNG?raw=true)

## Fire Evacuation - Focus (660 Seconds)
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework3/images/fire660.PNG?raw=true)

~~~
As the simulation progresses
to 720 seconds, the density maps
suggest that hallway 1 continued 
to be the main method of escape,
with exits 1 and 5 again being 
the exit of choice for agents.  
Exit 4 density stayed relatively 
high as well, servicing those agents
that work in the back of the building.
The mean of agent exits (including the 
number of agents who exited at/before 
the 660 second mark) was 50.5.
~~~

## Fire Evacuation - Simulation Density Map Data (720 Seconds)
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework3/images/firedensity3.PNG?raw=true)

## Fire Evacuation - Focus (720 Seconds)
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework3/images/fire720.PNG?raw=true)

~~~
At 780 seconds, there were no 
significant changes to the heat 
maps.  This is also reflected in
the fact that there were a very 
low number of increase in exits 
for each simulation (6 total agent
exits across 10 simulations).  
The mean of agent exits (including 
numbers of agents from the 660 
and 720 marks) was 51.1.  
Additionally, it appears that the
greatest concentration of agents 
that are "stuck" are located 
in the area 2 
offices (see screenshot below).
~~~

## Fire Evacuation - Simulation Density Map Data (780 Seconds)
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework3/images/firedensity4.PNG?raw=true)

## Fire Evacuation - Focus (780 Seconds)
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework3/images/fire780.PNG?raw=true)

~~~
As the simulation reaches the 
840 second mark, the density maps
generally show heat areas in 
hallway 1, the area 2 office area,
and exits 1 and 5.  Again, a low 
number of agents (only 4 agent) 
exited during this minute across
10 simulations.  The mean of 
agent exits (including all previous
exits) was  51.5, and the mean of 
agents that became casualties 
was 7.5.  Looking at simulations
1, 4, 6, and 10, which had the lowest
exit/highest casualty rates 
(at 9, 18, 9, and 9 casualties), 
it appears that the area 2 office 
area, and potentially hallway 1 are 
not wide enough to support a mass
exodus.  To combat this problem, 
potentially the area 2 office area 
could be redesigned, or the area 
could be converted to storage to 
remove great amounts 
of traffic in the area.
~~~

## Fire Evacuation - Simulation Density Map Data (840 Seconds)
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework3/images/firedensity5.PNG?raw=true)

## Fire Evacuation - Focus (840 Seconds)
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework3/images/fire840.PNG?raw=true)

~~~
ANALYSIS - Intensity and Traffic Timeplots
The traffic and intensity timeplots generally
parrallel what the density maps told us
in the analysis above.  Without taking 
into consideration the entryline, 
the traffic and intensity 
plots both show the highest rates 
in hallway 1,
and also hallway 4 (not reflected in 
the density likely due to a wider
dispersion of pedestrians going to
separate work areas).  The exits with the
highest traffic/intensity were consistenly 
exit 1 and exit 4, as rmirrored in the 
pedestrian density map data above.
~~~

## Fire Traffic Timeplot 
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework3/images/firetraffic.PNG?raw=true)

## Fire Intensity Timeplot
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework3/images/fireintensity.PNG?raw=true)

~~~
FINAL ANALYSIS
The data displayed above can 
be used in a myriad of different 
ways.  A human life is an extremely
valuable thing and the administrators 
of P2 should consider that
potentially the halls and the 
offices in area 2 could not facilitate
quick evacuation (under 4 minutes) and
thus could not feasibly sustain
a 0 casualty outcome given the current
blueprint of the building.  Based on 
the data I collected, UCF administrators
in responsibility of PII should focus
their attention on office area 2 and 
hall 1 (see screenshot below).

The next step
is to first get live data (in the form of 
a fire drill), and see if this 
data is accurate.  If it is accurate, 
then steps should be taken to convert 
the office space in area 2 to storage 
space (or some other type of function 
that decreases pedestrian activity in 
the area).  Also, it is unlikely that
the hallways could be widened, but if
the budget allows, potentially 
removing non-load bearing walls in
the center "island" office area 
(part of areas 1 and 2) and modular
walls could increase traffic flow 
through halls 1 and 2.  This data could
also be used to increase fire mitigation
measure such as fire extinguishers
and sprinklers down these halls, as they
are the most viable means of exit and
should be as clear as possible to
facilitate pedestrian traffic to safety
zones.  An additional step for building
administration could include rehearsing
fire drills monthly to decrease the
amount of time in the building which
will thus increase survivability.  
~~~

## Fire Evacuation - Administrative Focus Areas
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework3/images/fireoverall.PNG?raw=true)



Please use this YouTube link to view the fire evacuation simulation:
[P2 Fire Evacuation Simulation](https://youtu.be/e4CFg1bAB2Y)

~~~
References

Unknown Author.  Unknown Date.  
Maze-Dessert .PNG file utilized for 
maze, found via a google search.  
MIT.Edu.  Retrieved from 
https://scratch.mit.edu/projects/95364380/.

Kulig, Meghan.  April 2008.  
Firefighters Highlight Dangers of Smoke.
WEAU.COM.  Retreieved from 
http://www.weau.com/home/headlines/17398994.html. 

MacArthur, Keith.  Face to face/online
correspondence.  For Part 2, I posted 
a question in Piazaa on April 12th, 
2017 titled "AnyLogic Agent Behavior" 
regarding randomizing agent paths in the 
maze.  Keith replied by showing that a 
potential solution is the utilization of 
ped select outputs, which I then utilized 
in my maze.  Additionally, during a study 
session on April 20th, 2017, Keith showed
me how to format the input for freefunction 
into an event. 

UCF Office of Emergency Mangement.  
March 2015.  University of Central Florida
Fire Plan.  Retreived from 
https://emergency.ucf.edu/Plans/Fire%20Plan.pdf. 
~~~
