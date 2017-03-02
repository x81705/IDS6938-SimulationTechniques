#Homework 2 :  Discrete-Event Simulation Assignment

## IDS6938-Simulation Techniques - [University of Central Florida](http://www.ist.ucf.edu/grad/)

[University of Central Florida](http://www.ist.ucf.edu/grad/)
This is the framework for homework #2. 

The assignment is due: **Tuesday, March 28 at 11:59PM (EST)**

# Introduction
A Discrete-event Model simulates a complex system as an ordered sequence of well-defined events. Mathamatically Discrete-event models use Markov Processes, Queuing systems, events, probability / statistics, and random variables. The purpose of this assignment is to learn the mathmatical foundations, how to program these models, and how to simulate them. The assignment is due Tuesday, March 28, 2017 at 11:59 P.M.

Major parts for the Assignment
You canthinkg of the assignment broken up to 4 major parts:
* Empirical Tests of Randomness
* Markov Processes
* Discrete Event Simulation
* Composing a final report

The goal of this assignment is to become familiar with the concepts in the second third of the class. You will be expected to compose a *final report* which demonstrates your understanding on the material in each section of the assignment. Be visual! - Pictures say a thousand words so you do not have to. Show off your different configurations and really explore the assignment.

# Assignment
##Part 0 - Getting Started
Read the assignment. Sync your fork with the [main IDS6938 repository](https://github.com/hepcatjk/IDS6938-SimulationTechniques). Use CMake to create project files for the Homework 2 assignment (*Hint: and Discrete Lecture folders*). Set your *startup project* to the correct project. Test building and executing the homework 2 project. Look over and understand the framework and find the functions you need to edit for the assignment.



##Part 1: Empirical Tests of Randomness (20 pts).
We looked at different ways to generate [pseudo-random numbers](https://en.wikipedia.org/wiki/Pseudorandom_number_generator) and [quasi random numbers](https://en.wikipedia.org/wiki/Low-discrepancy_sequence). Generating random numbers are crucial to Discrete-Event simulations which rely on random variables and stochastic processes. This problem explores different random number generators, distributions, and statistics. Different [C++ pseudo-random numbers engines are instantiated](http://www.cplusplus.com/reference/random/) already for you. Also a a wide variety of standard distributions are implemented. Two quasi random number generators are also provided.
* **(a) - 3pts:** Output the results of five different random number engines, using a uniform distribution for values between [0-100]. Generate useful charts and statistics from the output to analyze how uniform these values truly are. You are expected to look at some advanced statistics and test, for example: tests like the Kolmogorov-Smirnov test, Chi-square test, Autocorrelation test, and Spearman’s Rank Correlation Coefficient are a few examples of ones your could use.)
* **(b) - 2pts:**  Vary *N* (amount of samples). How do things change.
* **(c) - 3pts:** Fix a random engine of your choice from part (a), and now vary five different [distributions](http://www.cplusplus.com/reference/random/) for just the psedo-random numbers. Again, analyze your results with graphs and statistics of choice.
* **(d)- 4pts:** Generate random numbers in two-dimensions for a unit square. Plot the results for the different random number engines. The vertical axis should vary N in increasing order. The horizontal axis should show of the random number engines.
* **(e)- 4pts:** Generate random numbers in two-dimensions for a unit square. Plot the results for the different distributions. The vertical axis should vary N in increasing order. The horizontal axis should show of the random number engines. (See [Random Numbers Webcourse page](https://webcourses.ucf.edu/courses/1246518/pages/random-numbers?module_item_id=10541423) for a rough idea what you should produce.)
* **(f)- 4pts:** Repeat parts (d) and (e) with a unit circle.

##Part 2 - Markov Processes (15 pts)

##Part 3 - Discrete-Event Simulation (45 pts)


##Part 4 - Implementing Extra Features (10 pts)
Implementing 2 features on the extra features list. Pick any feature on the "*extra features*" list below to customize your assignment to fit your interests. Please document this in your writeup.

##Part 5 - Final Report (10 pts)
Write up the results to the previous sections in the main *readme.md* in your forked repository. Turn in the URL for your fork in webcourses. Be visual. The report should contain the graphs and analysis requested. I have high expectations for the documentation here and you should allot the proper time to compose the writeup.


##Extra Features (Extra Credit - 25pts)
You have to implement two features from this list for Part 4. You may choose any two features you wish from this list. (Please explicitly note them in your *Readme.md*)

If you feel like going beyond the scope of the assignment, you should consider implementing more of the following extra features. *Get the assignment working without them first.* You can get a maximum of 25 points in extra credit. Simply implementing these things doesn't guarantee you a 25; you really need to go above and beyond to get the full amount. (*The instructor reserves the right to hand out extra credit as his he sees fit.*)

* **(5 Points)** - Implement and compare Halton, Hammersley, (Or another quasi method) Quasi sequences and add them to your analysis for appropriate subparts of Part 1.
* **(5 Points)** - Implement different distributions inside the Quasi random sequences and add them to your analysis for appropriate subparts of Part 1.
* **(5 Points)** - Implement and compare another (advanced) psedo random sequences and add them to your analysis for all subparts of Part 1 (Examples include: [PCG](http://www.pcg-random.org/), or [Random123](https://github.com/DEShawResearch/Random123-Boost)).
