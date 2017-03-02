#Charlie Timm -- Taking 1 Alibi Day
#Homework 1 : The Jello Cube (Continuous Simulation Assignment)
## IDS6938-Simulation Techniques - [University of Central Florida](http://www.ist.ucf.edu/grad/)



The assignment is due: Wednesday, February 27 at 11:59PM (EST); with alibi, and extension, March 2 at 11:59PM (EST)


## Part 1. Numerical Analysis of Integration Functions
a. Take integral of dy/dx = y-1/2*e^x/2*sin(5x)+5e^x/2*cos(5x), where initial condition for ODE is defined by y(0)=0.

~~~
ANS: y(x) = e^(x/2)sin(5x)
~~~
*Utilized Wolfram Alpha by inputting y'(x)=y-1/2*e^(x/2)*sin(5x)+5e^(x/2)*cos(5x) , y(0)=0

--
b. Translate mathematical formulas into df and exact functions.

~~~
ANS:
Compute the dy/dx
*/
double df(double x, double y)            //function for defining dy/dx
{
    return y - (1.0 / 2.0)*exp(x / 2.0)*sin(5.0 * x) + 5.0 * exp(x / 2.0)*cos(5.0 * x);
}


/*
Compute the exact answer
*/
double exact(double x)            //function for defining dy/dx
{
    return exp(x / 2.0)*sin(5.0 * x);
}
~~~
*Utilized Lecture6 Solution

--

c. Run 3 numerical integration solutions: RK1, RK2, and RK4 to generate numerical and exact values; use h=.1 for x = <0.0,
 10.0>. Graph results and exact solution.

~~~
ANS: 
Dr. Kider and I set up an example.txt file, 
which contained the printed values from the program, 
and transposed the values to excel. I then utilized 
excel to graph the values.  The excel tables show the 
acquired values and the graph below depicts 
RK1, RK2, RK4, and the exact solution.  
As will be demonstrated below, the RK4 and
Exact Solution are extremely close (within .2).

~~~
## Integration Values - RK1, RK2, RK4, and Exact Solution 
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework1/images/chart1.PNG?raw=true)
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework1/images/chart2.PNG?raw=true)
## Graph - RK1, RK2, RK4, and Exact Solution  
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework1/images/graph1.PNG?raw=true)

--

d. Plot error percentages for RK1, RK2, and RK4 in another graph.  Error defined by %error = |exact-apprx|/exact.

~~~
ANS:
Utilized the same excel spreadsheet and graphed the 
error percentages from the program (this utilzed the formula 
%error = |exact-approx|/exact).  The graph below depicts 
error percentage for RK1, RK2, and RK4.
~~~
## Graph - Error Percentages
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework1/images/graph2.PNG?raw=true)


--

e. Vary step size h = n where you define three n values for x = <0.0, 10.0>. Plot results for RK4 with 3 different n values with exact solutions. Plot the error rate.

~~~
ANS:
For this, I reran the program utilizing N =0.5, N=.25, and N=.10, 
by modifying the h variable.  For each iteration, I copied/pasted 
the RK4 and Error Data into a separate excel spreadsheet and graphed.
~~~
## Graph - RK4/Exact Solution
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework1/images/graph4.PNG?raw=true)
## Graph - Error Rate
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework1/images/graph3.PNG?raw=true)

--


f. Analyze results: 1. Describe how varying integration method changes accuracy, 2. What happens as you increase x value
to the accuracy, 3. How does varying step size effect accuracy, 4. Which method is most accurate and why (what is taken into
account in the solution). 

~~~
ANS:
1. As demonstrated by the graphs, as we go from RK1, RK2,
and RK4  the accuracy increases; this evidenced by a comparison 
between the values for each integration method and the exact 
solution.  It is clear that RK4 is the most accurate method 
comparing the results of RK1, RK2, and RK4 (refer to graph above).
2. As the X value increases, there will be a decrease 
in the accuracy of the integration as compared to exact solution; 
again, as demonstrated by the images below, we see the integrations 
getting further from the exact solution graphically.
3. The more steps we take the better, as we're increasing 
the amount of "slices" we're taking which is essentially 
increasing the accuracy; see graphs above for the
error rate when H=.5, .25, and .10.  This is also evidenced
in the graph above, with .10 as H having the lowest error rate.
4. RK4 is most accurate; again, through comparison of all 
integration methods and the exact solution, we can see that 
RK4 is most accurate by the graphs above; the reason for this is that we're 
taking four approximations to the slope, and more approximations 
result in greater accuracy.
~~~

~~~
References

Almodovar, Alex. Multiple conversations (both in-person and via email/text) 
regarding both Part I and Part II, 9FEB-2MAR17. For Part I, Alex provided 
guidance in how to fork repositories, and offered troubleshooting advice and 
guidance for running  code for integration solutions; compared 
my solution to his in order to see if I was on the right track.

Kider, Joseph.  Multiple conversations via email and during 
office hours on 22FEB-2MAR17 regarding errors compiling code,
printing functions, and general help determining if solution was correct.
~~~


##Part 2.

a. Forward Euler, midpoint integration, and RK4.  

b. Implement spring forces in JelloMesh::ComputerForces(ParticleGrid&grid), find good spring constants.

c. Collision and Penetration Detection.  

d. Collision and penetration response.  

e. Extra springs that simulate shear/bending resistance.  

~~~
ANS:
See code for A-E in Part II in JelloCube.sln in 
x81705 repository (linked via webcourses).  As of now, 
cylinder collision is not operational, but screenshots 
of the jellocube bouncing off the ground, jiggling, and 
maintaining structural integrity are shown below.  
Additionally, a video has been uploaded to YouTube, 
link provided in Part F. Implement Two Extra Features.
~~~
![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework1/images/successjello1.PNG?raw=true)

![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework1/images/successjello2.PNG?raw=true)

![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework1/images/successjello3.PNG?raw=true)

![](https://github.com/x81705/IDS6938-SimulationTechniques/blob/master/Homework1/images/successjello4.PNG?raw=true)

f. Implement two extra features  
~~~
ANS:
Uploaded movie using Icecream application to www.youtube.com (see link below); 
- Attempted to implement Sphere Collision... 
~~~
[https://youtu.be/-yUUop7f_EU] 


##Part 3
1.What is the effect of Ks and Kd parameters on the jello?

~~~
ANS: 
Ks is the spring constant and Kd is the dampening constant; therefore, they are
two opposing forces that come into effect when the jello hits the ground or the
surface of any object.  Through trial and error (and the help of Alex/Joe), I utilized values from 2000.0-10000.0 for Ks, and much lower values ranging from
1.0-5.0 for the Kd values.
~~~


2.What are the benefits and the drawbacks of the collision system used here?
What are some different ways in which it could be improved?

~~~
ANS: 
The overall benefit is that the jello interacts with its environment in a fairly
realistic fashion; the drawbacks (at least in my system) is that it appears to slightly hover above the ground and not be quite as affected by gravity/spring forces the way that I've seen a jello cube; additionally, if dropping from a certain height, there should be a mechanism to make the jello cube actually break structural integrity and fall into multiple pieces.  

The system could be improved by the utilization of better integration methods beyond RK4 to give a more realistic simulation; granted, more realism/accuracy is probably not needed given the nature of this project, as opposed to something like a NASA simulation testing the capabilities of a spacecraft.
~~~

3.What are some example systems you could model with Mass-spring simulations?
Explain how you would construct the model.

~~~
ANS: 
Cloth is an example of a system you could model with mass spring simulations; for the model, you would have to incorporate structural, shear, and bend springs and take into consideration that most cloth is not very elastic (Author Unknown, Date       Unknown).  To construct the model, cloth should be model as a triangle mesh of      particles, with the aforementioned spring forces formulated per triangle and in 
edge-adjacent triangles; additionally, an advanced technique called "flypapering" is utilized to give particles more freedom and thus realism (Baraff et. al, 2003).    Also, models involving cloth will usually utilize the Euler method.                 (Baraff et. al, 2003)
~~~

4.Does the jello behave realistically?  What integration method did you choose
to make the jello stable?

~~~
ANS: 
The jello behaves fairly realistically, although when it hits an object it 
tends to have more oscillation/jiggling than what I've experienced anecdotally.
I utilized RK4 to integrate, basically due to the fact that it was the default 
and appeared to have a good degree of accuracy; using other methods would have
decreased the accuracy of the simulation so I decided to stay with RK4.
~~~

5.How would you model and simulate water (in terms of continuous simulation)?

~~~
ANS: 
Likely would use particles to simulate the water molecules; we would have to delve
into the laws of physics as they relate to water and how it moves and what can cause that movement (Author Unknown, Date Unknown).  Additionally, could use the Lagragian
method to tracking the motion and particles over time in the simulation.
~~~



~~~
References

Almodovar, Alex. Multiple conversations (both in-person and via email/text) regarding both Part I and Part II, 9FEB-2MAR17. For Part II, Alex provided guidance/help in resolving contacts, help with floor interesections, cylinder collisions, as well as general help compiling/fixing syntax, constant/variable manipulation, and coding errors.  All coding has been labeled in locations where Alex has helped me.

Baraff, D., Witkin, A., and Kass, M.  (2003).  Untangling Cloth.  Pixar Animation  Studios.  
Retrieved from http://graphics.pixar.com/library/UntanglingCloth/paper.pdf

Kider, Joseph.  Conversations via email and during office hours on 22FEB-2MAR17 regarding errors compiling code, finding correct solutions for all functions, and general help with the composition/functionality of the JelloCube program.  All coding
has been labeled in locations where Joe has helped me.

Author Unknown. (Date Unknown).  Mass-Spring Systems PowerPoint.  Rensselaer       Polytechnic Institute.  Retrieved from https://www.cs.rpi.edu/~cutler/classes/advancedgraphics/S09/lectures/06_mass_spring_systems.pdf.
~~~

=======

