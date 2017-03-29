
# Charlie Timm
#Homework 2 :  Discrete-Event Simulation Assignment

## IDS6938-Simulation Techniques - [University of Central Florida](http://www.ist.ucf.edu/grad/)

[University of Central Florida](http://www.ist.ucf.edu/grad/)
 

The assignment is due: **Tuesday, March 28 at 11:59PM (EST)**
Will use one alibi day, making new due date: 
**Wed, Mar 29 at 11:59PM (EST)**
Total Alibi Days Used: 2


# Assignment

##Part 1: Empirical Tests of Randomness (20 pts).
We looked at different ways to generate [pseudo-random numbers]
* **(a) - 3pts:** Output the results of five different random number engines, using a uniform distribution for values between [0-100]. Generate useful charts and statistics from the output to analyze how uniform these values truly are. You are expected to look at some advanced statistics and test, for example: tests like the Kolmogorov-Smirnov test, Chi-square test, Autocorrelation test, and Spearman’s Rank Correlation Coefficient are a few examples of ones your could use.)

~~~
ANS:
I essentially just commented out code in random.cpp from Discreet2, 
keeping the uniform_real_distribution for all random number generator
engines. The first random number generator (RNG) I used was mt19937_64, 
followed by knuth_b, minstd_rand, and ranlux48, and sobol.  I 
copied the data into separate text files, and then plotted the 
data in excel (See Graphs Below).  Of note, with
this distribution it appeared that the limits (0,100) had far less
than the other numbers.  Additionally using excel, 
I ran the Chi-square Test, and Kolmogorov-Smirnov Test.  

I utilized the Chi-Square Test function in Excel to obtain the 
results below. Degrees of freedom are found by taking Rows-1 *
Columns-1, so in this case the DF=100; however the function in 
excel takes this into consideration. 
The Chi-Square Test p values indicates that all values are lower
than .05, which means they are statistically significant, but does
not prove they are distributed randomly and uniformly (see P value
chart below). With this in mind, MINISTD_RAND has the highest P value, 
and MT has the lowest value; as Joe mentioned in class, it should be noted 
this does not prove the hypothesis that the numbers are distributed 
uniformly and randomly (Turner, Gosia; obtained info about Chi-Sqr
from PowerPoint in references).

I learned/utilized the Kolmogorov-Smirnov Test in excel by watching 
a Youtube video (Davis, Jeff; see references below). The Komogorov-Smirnov Test 
results are listed in the chart below; because all the largest 
differences (D) values (found by taking the difference between each 
distribution and the expected value, and then manually searching for 
the data) are greater than the critical D (formula: 1.36/SQRT(100000)), 
uniform random distribution is likely not happening, as the difference in
D values indicates that there are varying distributions.  If we had lower
D values than the critical D, it would indicate that there is not enough
evidence to conclude there's major discrepancies between 
the two distributions.  The RANLUX appears to be the RNG that is closest
to the critical D value, and is thus closer to distributing random values
equally.
~~~

## Graph - Ministd_Rand Graph
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework2/images/ministdrandhisto.png?raw=true)
## Graph - Knuth_b Graph
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework2/images/knuthbhisto.png?raw=true)
## Graph - MT Graph
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework2/images/mthisto.png?raw=true)
## Graph - Ranlux Graph
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework2/images/ranluxhisto.png?raw=true)
## Graph - Sobol Graph
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework2/images/sobolhisto.png?raw=true)

## Chi-Squared Test Chart
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework2/images/chisqrgraph.PNG?raw=true)

## KS Test Chart
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework2/images/kstestchart.PNG?raw=true)


* **(b) - 2pts:**  Vary *N* (amount of samples). How do things change.

~~~
ANS:
I simply changed the N number in the program for each
RNG listed above to 1000 and 1000000.  I noticed that in general, the 
distributions appeared to roughly hold the same patterns even as
N increased; this is most
clearly seen in a comparison of these two graphs with the initial N value
conducted in Part A above (see graphs below; separate 1M graph displayed
with axes parameters to give full context with all values).
~~~

## Graph - Ranlux Comparison Graphs
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework2/images/b1.PNG?raw=true)
## Graph - Ranlux Expanded N=1M Graph
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework2/images/b6.PNG?raw=true)

## Graph - Sobol Comparison Graphs
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework2/images/b2.PNG?raw=true)
## Graph - Sobol Expanded N=1M Graph
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework2/images/b7.PNG?raw=true)

## Graph - Knuth_b Comparison Graphs
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework2/images/b3.PNG?raw=true)
## Graph - Knuth_b Expanded N=1M Graph
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework2/images/b8.PNG?raw=true)

## Graph - MINSTD Comparison Graphs
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework2/images/b4.PNG?raw=true)
## Graph - MINSTD Expanded N=1M Graph
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework2/images/b9.PNG?raw=true)

## Graph - MT Comparison Graphs
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework2/images/b5.PNG?raw=true)
## Graph - MT Expanded N=1M Graph
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework2/images/b10.PNG?raw=true)


* **(c) - 3pts:** Fix a random engine of your choice from part (a), and now vary five different [distributions](http://www.cplusplus.com/reference/random/) for just the psedo-random numbers. Again, analyze your results with graphs and statistics of choice.

~~~
ANS:
I picked the MT (Marsenne Twister) as it was suggested by Joe during office hours
due to its widespread use.  Using random.cpp in Discreet2, I utilized N = 100000, 
and then utilized the following distributions: Uniform Real, 
Normal, Uniform Int, Chi-Squared, and Cauchy Distributions.  
I found the code for Chi Squared and Cauchy in Discreet2 
under External Dependencies -> Random -> std.  For many distributions the 
parameters/inputs had to be adjusted to make the code work.


Based on the data I acquired, I followed the same procedure listed above to 
graph all datasets (refer to graphs below).  Of note, the MT with Uniform 
Int Distribution did not appear to have the same issue of values being 
skewed at 0 and 100.  Additionally, I observed that P values were all 
below .05 with the exception of Uniform Int, meaning they are stastically significant (other than Uniform Int)
but does not prove they are uniformly/randomly distributed 
(see below; note, possible corrupted data due
to obtaining 0s for three distributions).

NO TIME FOR KS TEST!!!!
NO TIME FOR KS TEST!!!!!
NO TIME FOR KS TEST!!!!!

~~~

## Graph - MT With Uniform Real Distribution
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework2/images/c1.PNG?raw=true)

## Graph - MT With Normal Distribution
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework2/images/c2.PNG?raw=true)

## Graph - MT With Cauchy Distribution
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework2/images/c3.PNG?raw=true)

## Graph - MT With Uniform Int Distribution
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework2/images/c4.PNG?raw=true)

## Graph - MT with Chi-Squared Distribution
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework2/images/c5.PNG?raw=true)

## Graph - Chi-Squared Test
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework2/images/c6.PNG?raw=true)


* **(d)- 4pts:** Generate random numbers in two-dimensions for a unit square. Plot the results for the different random number engines. The vertical axis should vary N in increasing order. The horizontal axis should show of the random number engines.

~~~
ANS:
For this part of the problem, I utilized the uniform real distribution with a range
from 0-1 and N of 100000, and simply changed the RNGs.  I subsequently ran the RNGs
with Ns of 1000 and 1000000 for each individual RNG. The order of RNGs I used was mt19937, followed by 
knuth_b, minstd_rand, ranlux48, and 
sobolo (which I ran from quasi.cpp file). 

I then used the raw results from each and plotted via excel (see 
chart below; due to graph constraints, utilized two separate pngs to 
better display data; possible issue with SOBOL, had to code out what Joe provided
at office hours to make data work).  As shown by the graphs, the patterns become
clearer as N increases.
~~~


## Graph - Unit Sqares - Knuth, Minstd, and MT
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework2/images/d1.PNG?raw=true)
## Graph - Unit Squares - Ranlux and Sobol
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework2/images/d2.PNG?raw=true)



* **(e)- 4pts:** Generate random numbers in two-dimensions for a unit square. Plot the results for the different distributions. The vertical axis should vary N in increasing order. The horizontal axis should show of the random number engines. (See [Random Numbers Webcourse page](https://webcourses.ucf.edu/courses/1246518/pages/random-numbers?module_item_id=10541423) for a rough idea what you should produce.)

~~~
ANS:
For this section, I ran the distributions twice and then plotted all graphs for
N= 500, 750, and 1000.  There are likely issues with the data of Cauchy and Chi-Squared due to parameters/inputs (see graphs below).
~~~

* **(f)- 4pts:** Repeat parts (d) and (e) with a unit circle.

~~~
ANS:
To obtain graphs for this section, I simply emplaced parameters from -1 to 1
in all distributions possible and then converted the 
coordinates to polar in excel and plotted (see below).
~~~


References
~~~
Almodovar, Alex. Multiple conversations (both in-person and via email/text) 
regarding assignment, 9MAR-29MAR17. For Part I, Alex provided 
help compiling the code when I received errors for initial compiling,
reminded me that Discreet 2 solutions were utilized and that nothing to 
queues/shoots and ladders code needed to be modified for Part I, and provided
general guidance for manipulation of distributions and inputs/parameters.

Davis, Jeff.  1 February 2010.  K-S Test (Youtube Video).  Youtube.com.  
Retrieved from https://www.youtube.com/watch?v=9Of2LTy5Sq0.  

Kider, Joseph.  Multiple conversations via email and during 
office hours on 21MAR-28MAR17 regarding errors compiling code,
printing functions, and general help determining if solution was correct.

Microsoft Office Support Page.  Accessed https://support.office.com/en-us/article/CHISQ-TEST-function-2e8a7861-b14a-4985-aa93-fb88de3f260f to look up
how to utilize Chi-Square Test in Excel.

Turner, Gosia. 4 February 2014.  Is it statistically significant? The chi-square test.  University of Oxford.  
Retrieved from  http://www.ox.ac.uk/media/global/wwwoxacuk/localsites/uasconference/presentations/P8_Is_it_statistically_significant.pdf . 
~~~

##Part 2 - Snakes and Ladders (Discrete Event Markov Chains and Monte Carlo Simulations) (30 pts)


* **(a) Null State Game transition matrix - 10pts:** The *null state game* is defined by a game with no snakes and no ladders. This simplifies the game to just the moves of the two dice rolls. Create the transition matrix for the null state game. 

~~~
ANS:
I used the code from class/piazza to create the transition matrix for the null state
game; also received help from William Netterville/Sarah Matthews
(see references below).
Please refer to Visual Studio files for coding.
~~~

* **(b) Simulate and analyze the results of Null State Game - 10pts:** What is the modal number of moves required by a single player to finish the game? Produce graphs to analyze the results and show how the game evolves over time for both methods. Plot useful statistics of the results such as percentage chance of finishing the game in n-moves, cumulative probability of finishing the game in n-moves, and other ways to convey useful information of the results.

~~~
ANS:
I used the code from class/piazza to create the transition matrix for the null state
game; also received help from William Netterville/Sarah Matthews 
(see references below).  Please 
refer to Visual Studio files for coding.  The modal number of moves is XXXX.  Graphs
for A and B are also included below and indicate that the game progresses...
~~~

* **(c) Simulate and analyze the results of Snakes and Ladders -10pts:**  Construct a new transition matrix based on the table:


Ladders From  | Ladders To | |  Snakes From  | Snakes To 
-------- | -------- | ------------- | -------- | -------- 
3|19| |11|7
15|37| |18|13
22|42| |28|12
25|64| |36|34
41|73| |77|16
53|74| |47|26
63|86| |83|39
76|91| |92|75
84|98| |99|70



Run the same simulation and analyze your results similar to part (b) for the proper game of *Snakes and Ladders* for both methods. How often are the snakes and ladders used, how do the probability of finishing change, etc? What is the maximum and expected amount of moves for the game? Use charts and graphs to illustrate these points.

~~~
ANS:
I used the code from class/piazza to create the transition matrix for the null state
game; also received help from William Netterville (see references below) .
~~~

* **(d) Think - 0pts:** If these games are built entirely on chance, do they require any strategy? Is it really a *game*, would you rather play games of chance or games of strategy?

~~~
ANS:
If the games are completely built on chance, by definition they do not require any
strategy, unless one was to know the engines/processes driving that chance, which to some degree all games are driven by.  Personally, I'd rather play a game of strategy
to have more control over the outcomes; skill or strategy games are generally determined by propensity of the individual to play, and also more importantly, their
devotion to practicing and thus becoming better at the game.  Therefore, to increase
my odds of winning through hard work/practice, I would choose a game of strategy.
~~~

~~~
References
Almodovar, Alex. Multiple conversations (both in-person and via email/text) 
regarding assignment, 9MAR-29MAR17. For Part II, Alex provided 
help with general problem solution for B/C.  All help received from Alex is 
documented in visual studio files.

Matthews, Sarah.  Multiple conversations (both in-person and via email) 
regarding assignment, 27-29MAR17.  For Part II, Sarah helped me modify the 
transition matrix; all help received from Sarah is documented in visual
studio files.

Netterville, William. Face to face conversations on 27MAR17 during study group. 
For Part II, William helped with the formulation of the transition matrix and where to input code from piazaa.  All help received from William is documented in
visual studio files.
~~~



##Part 3 - Discrete Event Simulation - Queue Simulation (30 pts)

* **(a) - 4pts:** To start create the senario in the figure above in *main.cpp*. Checkin will have a *mu* of 53 and accept new arrivals, the security gates will have a *mu* of 20, and will not accept new arrivials, boarding will have a *mu* of 80. You will have to set up  the appropriate *MM1_Queue* objects to capture the functionality above.

~~~
ANS: Please refer to coding in visual studio files.
~~~

* **(b) - 4pts:** You want to add a check that your process is within an error range *is_within_error_range(float)* where the error range will be 0.002. You also want to process the next event, and add an external arrival where marked.

~~~
ANS: Please refer to coding in visual studio files.
~~~

* **(c) - 3pts:** in *mm1_queue.cpp* : add code to caculate the expected results for: 
  *  expected_server_utilization 
  *    expected idle prob
  *   expected queue length 
  *  expected number customers 
  * expected waiting time
  * expected response time 

~~~
ANS: Please refer to coding in visual studio files.
~~~


***(d) - 4pts:** Write code to call the functions to output and generate data from the airport senario. Plot and analyze the useful statistics/results in the program of your choice.  (Hint -  basically call  *.output();* on the MM1_Queue objects you create. Hint2 - two other use functions are *get_current_time()* and  *plot_results_output()* call intially on your intial MM1_Queue object.)

~~~
ANS: Please refer to coding in visual studio files.  
In regards to useful data and statistics, the following charts display
interesting statistics about the data I obtained, and also implement
the Extra Credit Feature - Add a 2D Visualization to AnyLogic for Part 3.
~~~

***(e) - 15pts:** AnyLogic Simulation;

~~~
ANS:
- Note: I added AnyLogic files under the images folder 
in my repository for reference

Narrative of Construction:
To construct this simulation, I utilized the pedestrian library; all inputs were
left in default mode unless otherwise noted.  I first made a target line and a
ped source block.  I connected the ped source block to a Go To Block (referred
to as "GTCheckin"), and then emplaced a rectangular area to serve as the container
for pedestrians around a Wait block (named "CIwait"; inputted a delay of 53 minutes,  but for simulation changed to millisecs for quicker observation (repeated in next
wait areas as well)).  

From CIwait, I emplaced
a Go To block ("GTsecurity) and then a Wait block ("SecWait"; with a 20 min delay setting), followed by a Ped Select Output named "Security Queue", in which I only
connected 3 of the 5 outputs and put probabilities of all three at .333.  Following this, I emplaced another Go To block ("GTBoarding") and a Wait block ("BoardWait").

Finally, I emplaced a Go To block named "GTplane" and a Ped Sink named "End" to finish the simulation of pedestrians moving through airport security; I also emplaced waiting areas around all areas in which there is a delay.

I then built the model and ran it; see below for screen shots displaying
the flowchart constructed in AnyLogic and the simulation (of note, changed values from minutes to milliseconds so I could run more simulations).
~~~
## AnyLogic Flowchart
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework2/images/any1.PNG?raw=true)

## AnyLogic 2D Simulation Start
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework2/images/any2.PNG?raw=true)

## AnyLogic 2D Simulation Running
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework2/images/any3.PNG?raw=true)

## AnyLogic 2D Simulation Running
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework2/images/any4.PNG?raw=true)

## AnyLogic 2D Simulation End
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework2/images/any5.PNG?raw=true)

## AnyLogic 3D Simulation Running
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework2/images/any6.PNG?raw=true)

## AnyLogic 3D Simulation Running
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework2/images/any7.PNG?raw=true)

## AnyLogic 3D Simulation End
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework2/images/any8.PNG?raw=true)

## AnyLogic 3D Simulation Close Up
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework2/images/any9.PNG?raw=true)

## AnyLogic 3D Simulation Close Up
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework2/images/any10.PNG?raw=true)

~~~
References

Hendricks, Corey.  Face to face conversation on 27MAR17 during study group.  Corey
gave a quick intro to using Anylogic and showed me the pedestrian library to construct
the simulation.

Netterville, William. Face to face conversations on 27MAR17 during study group. For Part III, William helped me with the construction of formulas in mm1_queue.cpp by showing me where the formulas were on webcourses (and helped with formulation).  He also showed me the piazaa post detailing the coding in main.cpp, and helped with where and how to input the code.  All helped received from William is documented in
visual studio files.

Wileman, Joseph.  Face to face conversation on 28MAR17 after class.  Joe helped me
implement 3D visualization by helping me to understand where the system was recording
and also how to better view/see the simulation.

~~~


##Part 4 - Implementing Extra Features (10 pts)
* **(10 Points)** - Add a 2D visualization to AnyLogic for Part 3.
 
 ~~~
 ANS:
 This is documented in Part 3 through the PNGs posted.
~~~


##Part 5 - Final Report (10 pts)

~~~
ANS:
Write-up contained in this readme.md and forked to repository/linked on webcourses.
~~~

##Extra Credit - 25pts (Mandatory Extra Features noted in Part 4)
* **(10 Points)** - Add a 3D visualization to AnyLogic for Part 3.

~~~
ANS: This is documented in Part 3 through the PNGs posted.
~~~


* **(10 Points)** - Setup another resource allocation / queueing problem related to your research in Anylogic with a basic visualization

~~~
ANS:
Prior to deployment in the Army, many units go through what is called a Rapid
Fielding Initiative (RFI), which in essence gives all the Soldiers in the deploying
unit new/updated equipment to ensure they are prepared/mission ready.  
RFI is conducted due to both training exercises 
prior to deployment that break/ruin Soldiers
gear, and also the possibility that a unit does not 
have the newest model of equipment.  Units from the Army usually deploy in Brigade size elements (approx. 4400 Soldiers dispersed throughout five Battalions).  
In my future jobs at the Brigade/Division level, this will 
likely be an operation I will oversee in some capacity, 
and therefore a simulation could be a great 
predictor and aid in the planning process.

For the purpose of this simulation, I will simulate the RFI 
of a Battalion in order to get a good estimation of the time 
it will take the entire Brigade to receive this critical equipment; 
due to the fact that in my experience Battalions are usually 
understaffed, I will assume the number of Soldiers in each Battalion 
is 700, and that RFI personnel will be able to service 120 Soldiers 
per hour.  I will also have 6 stations that Soliders must process
to receive gear (Body Armor, Helmet, Uniforms, Boots, Load Bearing Equipment, Miscellaneous (equipment dependent on mission)).  I used 20 minute 
delays at all stations with the exception of Body Army, which in 
my experience usually takes roughly 40 minutes due to increased blocks of instruction/certification/inspection.  Please see the images below 
(of note, to run more simulations, changed the values from 
minutes to milliseconds).

In regards to results, this simulation accurately predicted 
a bottleneck in the beginning of the queue (which I have seen in 
every RFI I have attended), and also predicted approximately 
60 hours to equip an entire Battalion; anecodtally this seems 
a bit high to me (usually can pass an entire Battalion through 
in two days, but it is often broken up by the Company level); 
however, taking into account stragglers and people who missed 
the fielding for other reasons (sickness, training, etc.), 60 
hours is likely close to an accurate number to equip all personnel.
NOTE: AnyLogic model/files located in Homework 2 repository.

~~~
## AnyLogic RFI Flowchart
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework2/images/extra1.PNG?raw=true)

## AnyLogic RFI Flowchart w/ Soldiers Simulated
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework2/images/extra2.PNG?raw=true)

## AnyLogic 3D RFI Simulation Close Up
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework2/images/extra3.PNG?raw=true)

## AnyLogic 3D RFI Simulation Ending
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework2/images/extra4.PNG?raw=true)


* **(5 Points)** - Pick a research problem (from your dissertation, Energy Microgrids, Missle Defence...). Compare and contrast different software packages (AnyLogic, Simio, Simulu8, Arena etc). Convince me as your "manager/advisor" what advantages, weaknesses, and costs each program has. Come to a conclusion. Roughly sketch out how you would formulate the problem in the framework.

~~~
ANS:
For this section, the question I'm seeking to answer is, "What type of program
would provide a quick and accurate network simulations for initial modeling/simulation?".  This relates to my focus
on Cybersecurity in this graduate program at UCF, and also something (like the extra credit above), that will be very valuable to understand in my future positions in the Army.  I will compare the advantges/disadvantages of AnyLogic,
Simio, and Arena and formulate a recommendation to my superiors.

In regards to Arena, a major advantage is that it has been around since approximately 1995,
and is readily regarded as the most popular simulation tool in the world; this means there is a body of knowledge associated with the platform, and that there is likely major support for operations in this program (Vieira, Date Unknown).  Another major advantage personally, is that the Arena interface looks very similar to the AnyLogic interface, and thus I would likely have a greater likelihood of initially understanding the system (Vieira, Date Unknown).  While reading a case study comparing Arena and Simio completing the same model/simulation, it appeared that some of the major disadvantages of Arena were the lack of animation, the aesthetics of the system (did not look as realistic as Simio), and that in general it took longer to construct, was more complex, and less intuitive overall (Vieira, Date Unknown).

A major advantage of Simio is that there isn't any need to write code because the software runs on an object oriented system; for me personally, this likely means that it would be an easier system to use (Vieira, Date Unknown).  Another major advantage is that objects can be easily shared between users, which would decrease the amount of workload for personnel working on simulating network architecture, as they would not have to build networks from scratch (Vieira, Date Unknown).  Additionally, 2D/3D animation has been simplified in this program, which would be a great feature whilst presenting possible solutions during briefs (Vieira, Date Unknown).  The major disadvantage of Simio is that there are very few practicioners, and there could be issues with sharing products or working on teams with personnel who are not familiar with the program (Vieira, Date Unknown).

Finally, we'll cover advantages/disadvantages of AnyLogic.  The biggest advantage at this point is that I've had experience modeling/simulating with this platform, which means that there isn't as steep of a learning curve with this platform.  I found the GUI very intutive and feel that it is generally a user friendly piece of software.  Another advantage is that the software can execute three kinds of modeling (agent based, discreet event, and system dynamics), in the event the question needs to be scaled up to include other factors/parameters (Author Unknown, 2014).  Also, animation of models is relatively easy to setup, and greatly increases the efficacy of future presentations on the proposed quetion. That being said, a disadvantage is that AnyLogic does not allow Windows Communication Foundation, although at this point I do not believe this would have a major affect on the question above (Author Unknown, 2014).  Another major disadvantage for AnyLogic is the fact that it takes a long time to load (likely due to both the fact that it's running Java and my old OS on my personal computer).

We also most include price in our comparison of these products.  
For the purpose of this section,
I will assume that time is a factor and that all systems would be able to be obtained in roughly one week with minimum negotiations/licensing.  I will also assume that Student Additions will not be admitted due to the fact that most people working on this type of problem in the Army would not have Student status.  In regards to price, AnyLogic has a free version which has many features that 
we could immediately implement in our design process.  Simio also has a free version that can be utillized to run/simulate models (www. simio.com/products)  Arena has an average price of 89$ per month, but customer configurations can vary/scale, and annual subscription is required (www.arenasolutions.com/pricing).    
Without trying each, this is a difficult decision, but my recommendation would be to download both AnyLogic and Simio and see if there are enough features to meet mission accomplishment;  as long as there are no issues, based on price, either Simio or AnyLogic should be selected.

Taking all of the advantages/disadvantages into consideration, I would recommend the selection of AnyLogic due to its ease of use, scalability, intutive GUI, and price.  Also, a major consideration is familiarity with the system, and while I'm not an expert yet, I feel that I can navigate the system well enough to produce a quality product.

In regards to mapping out the problem above, I would first go to the AnyLogic site and find any models that could be utilized in the initial infrastructure.  By doing a quick cursory search, I found multiple models located at https://runthemodel.com/models/it_amp_telecom/ .  The goal of this model/simulation would be initally to simply simulate a given military networks
diagnostics(see picture below; obtained from Anylogic.com; eventually, after the model is working, we could start introducing attack/defense mechanisms/operations.


References
Author Unknown.  2014.  Simulators Comparison.  Critical Manufacturing.  Retrieved
from http://paginas.fe.up.pt/~ei09035/thesis/SimulatorsComparison_V1.pdf .

Author Unknown.  Date Unknown.  Network Infrastructure Picture.  Anylogic.  Retrieved
from http://www.anylogic.com/consulting/information-and-telecommunication-networks .

Vieira, Antonio, et al.  Date Unknown.  Comparison of Simio and Arena Simulation
Tools.  University of Minho, Campus Gualtar.  Retreived from 
https://repositorium.sdum.uminho.pt/bitstream/1822/36949/3/SIMIO_vs_Arena%20@140606.pdf . 
~~~
## AnyLogic IT/Telecom Network Modeling Picture (Anylogic Website)
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework2/images/anylogic.jpg?raw=true)



