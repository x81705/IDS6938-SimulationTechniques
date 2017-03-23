
# Charlie Timm
#Homework 2 :  Discrete-Event Simulation Assignment

## IDS6938-Simulation Techniques - [University of Central Florida](http://www.ist.ucf.edu/grad/)

[University of Central Florida](http://www.ist.ucf.edu/grad/)
 

The assignment is due: **Tuesday, March 28 at 11:59PM (EST)**


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
data in excel (See Graphs Below).  Additionally using excel, 
I ran the Chi-square Test, and Kolmogorov-Smirnov Test.

I utilized the Chi-Square Test function in Excel to obtain the 
results below. Degrees of freedom are found by taking Rows-1 *
Columns-1, so in this case the DF=100; however the function in 
excel takes this into consideration. 
The Chi-Square Test p values indicates that all values are lower
than .05, which means they are statistically significant, or that
the numbers are likely to some degree to be distributed uniformly 
and randomly. Additionally, MINISTD_RAND has the highest value, 
and MT has the lowest value; this likely means that MT is the most 
uniform for the random values.

I learned/utilized the Kolmogorov-Smirnov Test in excel by watching 
a Youtube video (see references below). The Komogorov-Smirnov Test 
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
RNG listed above to 1000 and 1000000.  I noticed that in general, a more
distinct pattern emerged as N increased for all RNGs.

(See graphs below)
~~~

* **(c) - 3pts:** Fix a random engine of your choice from part (a), and now vary five different [distributions](http://www.cplusplus.com/reference/random/) for just the psedo-random numbers. Again, analyze your results with graphs and statistics of choice.

~~~
ANS:
I picked the MT (Marsenne Twister) as it was suggested by Joe during office hours
due to its widespread use.  Using random.cpp in Discreet2, I utilized N = 100000, 
and then utilized the following distributions (all from 0,100): Uniform Real, Normal, Uniform Int, Chi-Squared, and Cauchy Distributions.  I found the code for Chi Squared
and Cauchy in Discreet2 under External Dependencies -> Random -> std.

NORMAL and CAUCHY NOT WORKING (producing weird and negative numbers), FISHER and 
WEIBULL and GAMMA NOT WORKING AT ALL

CAN I DO UNIFORM REAL AGAIN, OR PICK ANOTHER?  WANT TO COMPARE UNIFORM REAL AND
UNIFORM INT; WHAT DOES PSEUDO RANDOM NUMBERS MEAN IN THE QUESTION?  CAN I JUST
RUN THE PROGRAM?

Based on the data I acquired....X.  Please refer to the charts below.
~~~


* **(d)- 4pts:** Generate random numbers in two-dimensions for a unit square. Plot the results for the different random number engines. The vertical axis should vary N in increasing order. The horizontal axis should show of the random number engines.

~~~
ANS:
For this part of the problem, I utilized the uniform real distribution with a range
from 0-1 and N of 100000, and simply changed the RNGs.  I subsequently ran the RNGs
with Ns of 1000 and 1000000 for each individual RNG. The order of RNGs I used was mt19937, followed by knuth_b, minstd_rand, ranlux48, and sobolo (which I ran from quasi.cpp file). I then used the raw results from each and plotted via excel (see 
chart below).

CAN I JUST USE THE RANDOM NUMBER GENERATOR TO SIMULATE X AND Y?  OR DO I SIMPLY
DECREASE N VALUES?

HOW DO WE CHANGE SOBOL RANGE FROM 0-1????  WENT THROUGH BOTH QUASI AND SOBOL AND 
COULDN"T FIND INPUT...
~~~

* **(e)- 4pts:** Generate random numbers in two-dimensions for a unit square. Plot the results for the different distributions. The vertical axis should vary N in increasing order. The horizontal axis should show of the random number engines. (See [Random Numbers Webcourse page](https://webcourses.ucf.edu/courses/1246518/pages/random-numbers?module_item_id=10541423) for a rough idea what you should produce.)

~~~
ANS:
Same issues with distributions...need to fix ASAP!
~~~

* **(f)- 4pts:** Repeat parts (d) and (e) with a unit circle.

~~~
ANS:
Same issue with SOBOL as above for part D, how to input -1,1 in that program

For differing distributions, need to check with Joe for if I'm doing them right


~~~
References

Almodovar, Alex. Multiple conversations (both in-person and via email/text) 
regarding assignment, 9MAR-28MAR17. For Part I, Alex provided 
help compiling the code when I received errors for initial compiling,
reminded me that Discreet 2 solutions were utilized and that nothing to 
queues/shoots and ladders code needed to be modified for Part I, and provided
general guidance for manipulation of distributions.

Davis, Jeff.  1 February 2010.  K-S Test (Youtube Video).  Youtube.com.  
Retrieved from https://www.youtube.com/watch?v=9Of2LTy5Sq0.  

Kider, Joseph.  Multiple conversations via email and during 
office hours on 21MAR-28MAR17 regarding errors compiling code,
printing functions, and general help determining if solution was correct.

Microsoft Office Support Page.  Accessed https://support.office.com/en-us/article/CHISQ-TEST-function-2e8a7861-b14a-4985-aa93-fb88de3f260f to look up
how to utilize Chi-Square Test in Excel.

Turner, Gosia. 4 February 2014.  Is it statistically significant? The chi-square test.  University of Oxford.  
Retrieved from  http://www.ox.ac.uk/media/global/wwwoxacuk/localsites/uasconference/presentations/P8_Is_it_statistically_significant.pdf. 

~~~

##Part 2 - Snakes and Ladders (Discrete Event Markov Chains and Monte Carlo Simulations) (30 pts)

##### Background
The classic game has 100 positions on the board. You toss one die, and move squares based on the result of the die. If you land on a ladder you move up the ladder to a higher numbered square. If you land on a snake's mouth, you descend to a lower numbered square. For purposes of simulation, we will add one extra square 0 (starting position). So there are 101 positions on the board.

The game is **memoryless** - your progression to the next position is independent of how you arrived there (opposed to Blackjack or Candyland where your progression is based on what cards have been drawn). A Markov Chain defines the probability of a move from state *i* to state *j* by a **Transition Matrix**, *T*. So in the case of *Snakes and Ladders* the dimensions of a transition matrix is 101x101.

* **(a) Null State Game transition matrix - 10pts:** The *null state game* is defined by a game with no snakes and no ladders. This simplifies the game to just the moves of the two dice rolls. Create the transition matrix for the null state game. The Transition Matrix would be decided by the roll of a fair, six-sided die, so it would start to look like:
<BR>![](images/null.png?raw=true)<BR>
From state 0 it is equally probable of landing on squares 1-6. From state 1 t is equally probable of landing on squares 2-7, and so on. Create this transition matrix. The end is trickier, we will consider any roll past 100 a win case. (Opposed to rolling exactly onto square 100.) Confirm you have a well formed stochastic matrix (Write checks for confirming each row of T sums to one and all elements are non-negative). The Transition Matrix methods can be found in the TransitionMatrix.h file.

~~~
ANS:
Used the code from class and the tips for building a complicated transition matrix
on piazza.
~~~

* **(b) Simulate and analyze the results of Null State Game - 10pts:** What is the modal number of moves required by a single player to finish the game? We will be simulating the game two different ways. **(1) Markov Chain**: The game can be analyzed with a row vector, *v* with 101 components, representing the probabilities that the player is on each of the positions. V(0) is (1,0,0,...,0) since we know we start at square 0. v evolves by: <BR>![](images/prob.png?raw=true)<BR>
For this part (1) use the *Markov project* in the Snake and Ladders starter code.<BR>
**(2) Monte Carlo**: he will will use a monte carlo process to solve our Discrete Time Markov Chains. Here (2) use the DTMC project, and utilize the DTMC method similar to what we did in class. <BR><BR>Produce graphs to analyze the results and show how the game evolves over time for both methods. Plot useful statistics of the results such as percentage chance of finishing the game in n-moves, cumulative probability of finishing the game in n-moves, and other ways to convey useful information of the results.

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
* **(d) Think - 0pts:** If these games are built entirely on chance, do they require any strategy? Is it really a *game*, would you rather play games of chance or games of strategy?


##Part 3 - Discrete Event Simulation - Queue Simulation (30 pts)

This problem will look at queues and commonly used performance measures. For this problem we will look to design a simple airport security check. We will make the following assumptions: (1) there is only one airline - Southwest; (2) passengers' interarrival times are independent and identically distributed (IID) with an exponential distribution with mean 1 / lambda. The service times are also assumed to be IID and exponentially distributed random variables with mean 1 / mu.
<BR>![](images/queue.png?raw=true)<BR>
When a passanger arrives they have to wait in a queue to present their ID and ticket to the gate agent with all the other passengers. Once approved by the agent they will have to pass through a security check. Since this is Orlando, there are only 3 open metal/screening devices open and again passangers have to wait in a queue. After passing through security you again have to wait in a queue to board your plane.

* **(a) - 4pts:** To start create the senario in the figure above in *main.cpp*. Checkin will have a *mu* of 53 and accept new arrivals, the security gates will have a *mu* of 20, and will not accept new arrivials, boarding will have a *mu* of 80. You will have to set up  the appropriate *MM1_Queue* objects to capture the functionality above.
* **(b) - 4pts:** You want to add a check that your process is within an error range *is_within_error_range(float)* where the error range will be 0.002. You also want to process the next event, and add an external arrival where marked.
* **(c) - 3pts:** in *mm1_queue.cpp* : add code to caculate the expected results for: 
  *  expected_server_utilization 
  *    expected idle prob
  *   expected queue length 
  *  expected number customers 
  * expected waiting time
  * expected response time 
*  **(d) - 4pts:** Write code to call the functions to output and generate data from the airport senario. Plot and analyze the useful statistics/results in the program of your choice.  (Hint -  basically call  *.output();* on the MM1_Queue objects you create. Hint2 - two other use functions are *get_current_time()* and  *plot_results_output()* call intially on your intial MM1_Queue object.)  
* **(e) - 15pts:** Download the personal edition of **[Anylogic](http://www.anylogic.com/)**, read through the [documentation](http://www.anylogic.com/learn-simulation) as needed, and set up the same type of simulation discussed above.


##Part 4 - Implementing Extra Features (10 pts)
Implementing 2 features on the extra features list. Pick any feature on the "*extra features*" list below to customize your assignment to fit your interests. Please document this in your writeup. (*Note: These should total 10pts. You could successfully implement a feature worth 10pts or greater. This also fulfills this requirement. The features are assigned points based on difficulty. The 5pt features are more straightforward.*)

##Part 5 - Final Report (10 pts)
Write up the results to the previous sections in the main *readme.md* in your forked repository. Turn in the URL for your fork in webcourses. Be visual. The report should contain the graphs and analysis requested. I have high expectations for the documentation here and you should allot the proper time to compose the writeup.


##Extra Features (Extra Credit - 25pts)
You have to implement two features from this list for Part 4. You may choose any two features you wish from this list. (Please explicitly note them in your *Readme.md*)

If you feel like going beyond the scope of the assignment, you should consider implementing more of the following extra features. *Get the assignment working without them first.* You can get a maximum of 25 points in extra credit. Simply implementing these things doesn't guarantee you a 25; you really need to go above and beyond to get the full amount. (*The instructor reserves the right to hand out extra credit as his he sees fit.*)

* **(5 Points)** - Implement and compare Halton, Hammersley, (Or another quasi method) Quasi sequences and add them to your analysis for appropriate subparts of Part 1.
* **(5 Points)** - Implement different distributions inside the Quasi random sequences and add them to your analysis for appropriate subparts of Part 1.
* **(5 Points)** - Implement and compare another (advanced) psedo random sequences and add them to your analysis for all subparts of Part 1 (Examples include: [PCG](http://www.pcg-random.org/), or [Random123](https://github.com/DEShawResearch/Random123-Boost)).
* **(20 Points)** - Complete Part 2 with a different board game. Construct the game's transition matrix, simulate the game, and analyze the results (Run the game past the instructor).
* **(20 Points)** - Complete Part 2 with a 3D version of Snakes and Ladders. Construct the game's transition matrix, simulate the game, and analyze the results.
* **(10 Points)** - Provide code in (Python, R, Matlab...) that demonstrates an animation of the board itself evolving overtime for Snakes in Ladder for part 2. 
* **(10 Points)** - Add a 2D visualization to AnyLogic for Part 3.
* **(10 Points)** - Add a 3D visualization to AnyLogic for Part 3.
* **(5 Points)** - Pick a research problem (from your dissertation, Energy Microgrids, Missle Defence...). Compare and contrast different software packages (AnyLogic, Simio, Simulu8, Arena etc). Convince me as your "manager/advisor" what advantages, weaknesses, and costs each program has. Come to a conclusion. Roughly sketch out how you would formulate the problem in the framework.
* **(10 Points)** - Create an Anylogic simulation for Part 2 - Snakes and Ladders.
* **(10 Points)** - Setup another resource allocation / queueing problem related to your research in Anylogic with a basic visualization
* **(10 Points)** - Setup up SmartGrid or a Microgrid System that creates resources of power from wind, solar, and electric grid. Set up various devices in your house to draw power. [Reference 1](http://www.sciencedirect.com/science/article/pii/S1877050916301740),   [Reference 2](http://www.tandfonline.com/doi/full/10.1080/19401493.2013.866695?src=recsys&).
* **(25 Points)** - Set up a discrete simulation of your choice that uses an approved real-time data source and visualizes the results. (See instructor for approval).
* **(N Points)** - You are welcome to make suggestions for a feature of your own choosing, but they must be approved by instructor before implementing.