# Charlie Timm

# Homework 3 : Agent Based Simulation Assignment 

## IDS6938-Simulation Techniques - [University of Central Florida](http://www.ist.ucf.edu/grad/)

[University of Central Florida](http://www.ist.ucf.edu/grad/)
This is the framework for homework #3. 

The assignment is due: **Monday, April  24 at 11:59PM (EST)**
With Final Alibi, due date is: **Tuesday, April 25 at 11:59PM (EST)**
Total Alibi Days Used (prior to this project): **2**

# Introduction
The goal of this assignment is to enable the behavioral animation of vehicle-like walking agents. 

You will be expected to compose a *final report* which demonstrates your understanding on the material in each section of the assignment. Be visual! - Pictures say a thousand words so you do not have to. Show off your different configurations and really explore the assignment.


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


**(b) - 20 points**: In this part of the assignment you will need to implement 6 types of individual behaviors and 5 types of group behaviors. Create the following behaviors through appropriate computation of V<sub> d</sub>  and θ<sub>d</sub>  commands:
* Seek
* Flee
* Arrival
* Departure
* Wander
* Obstacle Avoidance

**(c) - 20 points**: Implement the functions for the following group behaviors: 
* Seperation
* Cohesion 
* Alignment 
* Flocking
* Leader Following

~~~
References

Almodovar, Alex. Multiple conversations (both in-person and via email/text) 
regarding assignment, 9MAR-29MAR17. For Part II, Alex provided 
help with general problem solution for B/C (to no avail, program is still not outputting).  
All help received from Alex is documented in visual studio files.

MacArthur, Keith.  For Part 2, I posted a question in Piazaa on April 12th, 2017 titled "AnyLogic Agen Behavior" regarding randomizing agent paths in the maze.  Keith replied by showing that a potential solution is the utilization of ped select outputs, which I then utilized in my maze. 

Netterville, William. Face to face conversations on 27MAR17
during study group. For Part II, William helped with the 
formulation of the transition matrix and where to input 
code from piazaa.  All help received from William is 
documented in visual studio files.
~~~


# Part 2 - Simulating A Simple Pedestrian Flow

**(a) - 0 points**: Follow the Anylogic example for the [Subway Entrance example]

~~~
ANS: I completed the tutorials with no major issues (screenshot included below; did not include 3D models (will be reflected in part 2B)).
~~~
## Subway Entrance Model/Simulation 
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework3/images/2a1.PNG?raw=true)


**(b) - 20 points**: Create a maze. Generate the pdm, stats, and animations like before. Vary [parameters in your agents](https://help.anylogic.com/index.jsp?topic=/com.xj.anylogic.help/html/_PL/reference/Attributes.html) to give them different behaviors and show the pedistrians change how they navigate the maze.

**(c) - 30 points**: Model and analyze a building (or floor/outdoor space/stadium) on campus. (There is help on piazza how to find rough building plans - we expect something plausible). Create a senario: evacuation, daily office routine, special event, normal egress.... etc., and model and design your own experiment to determine if the building design suits the needs of its users. Start with photographs of your site, describe your site, describe your senario and hypothesis. Then use an agent-based pedistrian simulation to visualize your experiment's results.

~~~
References

Almodovar, Alex. Multiple conversations (both in-person and via email/text) 
regarding assignment, 9MAR-29MAR17. For Part II, Alex provided 
help with general problem solution for B/C (to no avail, program is still not outputting).  
All help received from Alex is documented in visual studio files.

MacArthur, Keith.  For Part 2, I posted a question in Piazaa on April 12th, 2017 titled "AnyLogic Agen Behavior" regarding randomizing agent paths in the maze.  Keith replied by showing that a potential solution is the utilization of ped select outputs, which I then utilized in my maze. 

Netterville, William. Face to face conversations on 27MAR17
during study group. For Part II, William helped with the 
formulation of the transition matrix and where to input 
code from piazaa.  All help received from William is 
documented in visual studio files.
~~~