# Charlie Timm


# Homework 3 : Agent Based Simulation Assignment 

## IDS6938-Simulation Techniques - [University of Central Florida](http://www.ist.ucf.edu/grad/)

[University of Central Florida](http://www.ist.ucf.edu/grad/)
This is the framework for homework #3. 

The assignment is due: **Tuesday, April  25 at 11:59PM (EST)**
With Final Alibi, due date is: **Wednesday, April 26 at 11:59PM (EST)**
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

Almodovar, Alex. Multiple conversations (both in-person and via email/text) 
regarding assignment, 9MAR-29MAR17. For Part II, Alex provided 
help with general problem solution for B/C (to no avail, program is still not outputting).  
All help received from Alex is documented in visual studio files.


Matthews, Sarah. Multiple face to face/digital conversations from 13APR-26APR17. For Part I, Sarahm helped me with multiple function syntax/formatting and value manipulation.  All help received from Sarah is 
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
~~~
ANS: 
INTRODUCTION/ASSUMPTIONS/INIITAL CONDITIONS
This maze would replicate something similar to mazes commonly found in amusement parks around the globe.  There are two areas in which the agents can "see" dead ends and do not choose this path (see screenshot below); we are making the assumption that this maze is conducted in a medium light levels, and that agents will be able to generally see the path in front of them.  We will also assume that due to the difficulty of the maze, that after choosing a wrong path, agents will be redirected back to the decision point, and will then have an equal probability of choosing all paths.

Additionally, we will assume that this maze will replicate peak hours, with 5 agents arriving per minute (additionally, initial speed of .3 to .7 meters per second distributed uniformly, and a comfortable speed of 1 to 2 meters per second distributed unifromly, with no limit on agent number; will assume that the maze is very popular and that it is a weekend/federal holiday where the maximum traffic will occur).  

CONSTRUCTION OF THE MAZE/INITIAL CONDITIONS 
I first searched via google for an image of a maze, and then imported it to AnyLogic (maze obtained from MIT.edu; see references below).  During initial probelm solving, I constructed the maze and populated it with agents, but realized that the agents were simply taking the path of least resistance to the exit, and not taking any dead-end turns.  I posted a question via Piazaa regarding this issue, and saw that other students had used the pedSelect node to work around this problem (MacArthur, Keith; see references below). I utilized this method of emplacing multiple pedSelect nodes (linked to target lines) to simulate agents choosing a path based on equal probability.   


ANALYSIS
To analyze the data and display stats, I added a pedestrian density function, and then added graphs for both traffic and intensity, in which traffic is the number of pedestrians crossing the ped flow statistics lines in an hour (model time), and intensity is defined as the traffic divided by the line length.

I initially populated the maze with 5 agents per minute (leaving all other settings at default) and then through running the simulation ten times and recording the number of agents that exited the maze, I found an average of approximately 230 agents would be able to complete the maze within 60 minutes (see screenshot below).  

I then took screenshots every 900 seconds (or every 15 minutes (+- 5 seconds), model time) to analyze the data, and ran the simulation ten times.  The screenshots below show the coalated data, and indicate XYZ.

One of the big takeaways from this was the average (mean) total number of agents/customers that made it through the maze after ten simulations, which I calculated to be 244.4 agents (summed each trial, and then divided by 10).  This number could be used to calculate the number of employees needed to properly man the amusement park.

For the 900 second mark, the major consistency was that the high pedestrian density marker was at the target line 1 marker, with 7 out of ten simulations displaying an orange/red in the pedestrian statistics function, and the TL2 statistics in one of the top two positions for both traffic and intensity graphs (see screenshots; the first indicates all target lines, the second shows the data taken at 900 seconds from each of the ten simulations).

For the 1800 second data, while there was still major activity in/around the TL2 corridor (7 out of 10 displaying significant traffic/intensity), the area of higher traffic/intensity based on the pedestrian traffic density heat map was in vicinity of the TL7 statsitics line (9 of 10 displaying orange/red, even though the T7 statistics line does not feature prominently in any of the graphs); this is likely due to the fact that all agents must pass through this corridor, and that at this time in the simulation there are simply more agents in this general area (see screenshots below; the first indicates the area of highest pedestrian density based off the heat map, and the second shows all data taken at 1800 seconds from each of the ten simulations).  Additionally, there was increased density in vicinity of TL10 (5 of 10 displaying orange/red on the heat map).

For the 2700 second data, the data remained relatively similar to the 1800 second data, with the two main areas of traffic/intensity/density being in the vicinity of TL2 and TL7.  Additionally, there was increased density measure in the vicinity of TL10, with 6 of 1- displaying orange/red on the heat map).

For the 3600 second data, the data remained relatively similar to the 1800 second data, with the two main areas of traffic/intensity/density being in the vicinity of TL2 and TL7.  Additionally, there was increased density measure in the vicinity of TL10, with 6 of 1- displaying orange/red on the heat map).

I also found that areas 1 and 2 consistently had the highest concentration of traffic; this could be used in emergency planning, and also mitigation factors such as fire extinguishers/sprinkler emplacement.

PARAMETER CHANGE

To change the parameters, I varied the speed from an initial speed of .3 to .7 meters per second, to 1 to 1.5 meters per second, as I feel like in the beginning of a maze that the rate would be increased given the lack of path choices for this maze initially; I then decreased the rate to .5 to 1 meter per second, again, with consideration for the the assumption of medium lighting levels and the difficulty of the maze.  

Additionally, I added groups within the simulation as often times many people will go to social activities such as this with friends (initial conditions for group as follows: put a group size between 1-4 with uniform discreet distribution, set the interarrival time to within 1 second to simulate group arriving together, put the group formation as front, as there is often one person leading the group).

ANALYSIS 2


FINAL ANALYSIS
The most striking differences I saw were....
The most significant finding was...
This could be used for...
Please use this YouTube link to view the simulation during initial conditions:
(http://www.youtube.com/)
Please use this YouTube link to view the simulation during modified conditions:
(http://www.youtube.com/)

~~~

## Initial Model
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework3/images/3b8.PNG?raw=true)

## Initial Condition 3D 
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework3/images/2a1.PNG?raw=true)

## Subway Entrance Model/Simulation 
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework3/images/2a1.PNG?raw=true)

## Subway Entrance Model/Simulation 
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework3/images/2a1.PNG?raw=true)

## Subway Entrance Model/Simulation 
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework3/images/2a1.PNG?raw=true)

## Subway Entrance Model/Simulation 
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework3/images/2a1.PNG?raw=true)


**(c) - 30 points**: Model and analyze a building (or floor/outdoor space/stadium) on campus. (There is help on piazza how to find rough building plans - we expect something plausible). Create a senario: evacuation, daily office routine, special event, normal egress.... etc., and model and design your own experiment to determine if the building design suits the needs of its users. Start with photographs of your site, describe your site, describe your senario and hypothesis. Then use an agent-based pedistrian simulation to visualize your experiment's results.

~~~
ANS: I first obtained digital photgraphs of the floor plan of the Partnership II's first floor.  I also walked through the first floor and the perimeter of the building to confirm all office locations/exits.  I then imported the image files to AnyLogic, and began to trace the floor plan.

After creating the floor plan for the first floor, I then demarcated different areas where people will be working, and set the probability equally for agents using a pedSelect node (equal distributions within each of the 11 areas (.09)).


~~~

~~~
References

Unknown Author.  Unknown Date.  Maze-Dessert .PNG file utilized for maze, found via a google search.  MIT.Edu.  Retrieved from https://scratch.mit.edu/projects/95364380/.

Almodovar, Alex. Multiple conversations (both in-person and via email/text) 
regarding assignment, 9MAR-29MAR17. For Part II, Alex provided 
help with general problem solution for B/C (to no avail, program is still not outputting).  
All help received from Alex is documented in visual studio files.

MacArthur, Keith.  Face to face/online correspondence.  For Part 2, I posted a question in Piazaa on April 12th, 2017 titled "AnyLogic Agen Behavior" regarding randomizing agent paths in the maze.  Keith replied by showing that a potential solution is the utilization of ped select outputs, which I then utilized in my maze.  Additionally, during a study session on April 20th, 2017, Keith showed me how to format the input for freefunction into an event.  


~~~