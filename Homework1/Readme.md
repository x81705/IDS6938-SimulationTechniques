#Charlie Timm
#Homework 1 : The Jello Cube (Continuous Simulation Assignment
## IDS6938-Simulation Techniques - [University of Central Florida](http://www.ist.ucf.edu/grad/)


This is the framework for homework #1. Please first read the [homework writeup](HomeWork%231.pdf).

The assignment is due: Monday, February 27 at 11:59PM (EST)

| undeformed jello  | deformed jello |
| ------------- | ------------- |
| ![](images/undeformed3.png?raw=true)  | ![](images/deformed3.png?raw=true) |



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
Joe and I set up an example.txt file, which contained the printed values from the 
program, and transposed to the values to excel. I then utilized excel to graph the values.  The graph below depicts RK1, RK2, RK4, and the exact solution.

![(image/graph1.png?raw=true)]![](http://)!

IMAGE DOESNT DISPLAYYYY!!!!!!!!!!!!!!!!!!!!!!!!
~~~

--

d. Plot error percentages for RK1, RK2, and RK4 in another graph.  Error defined by %error = |exact-apprx|/exact.

~~~
ANS:
Utilized the same excel spreadsheet and graphed the error percentages from the program (this utilzed the formula %error = |exact-approx|/exact).  The graph below depicts error percentage for RK1, RK2, and RK4.

![(image/graph2.png?raw=true)]![](http://)!
IMAGE DOESN"T DISPLAY!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
~~~

--

e. Vary step size h = n where you define three n values for x = <0.0, 10.0>. Plot results for RK4 with 3 different n values with exact solutions. Plot the error rate.

~~~
ANS:
For this, I reran the program utilizing N =0.5, N=1.0, and N=5.0, by modifying the h variable.  For each iteration, I copied/pasted the RK4 and Error Data into a separate excel spreadsheet and graphed.

INSERT IMAGES!!!!!!!!!!!!!!!!!!!!!!!!!

~~~

--
f. Analyze results: 1. Describe how varying integration method changes accuracy, 2. What happens as you increase x value
to the accuracy, 3. How does varying step size effect accuracy, 4. Which method is most accurage and why (what is taken into
account in the solution). 

~~~
ANS:
1. From class, in general as we go from RK1-RK4 the accuracy increases; this evidenced by a comparison between the values for each integration method as compared with the exact value obtained. 
2. Increasing X value should increase the accuracy, as we're allowing more iterations to occur.
3. Kind of related to 2, the more steps we take the better, so as we decrease H value, the more steps we have and the more accuracy.
4. RK4 is most accurate; again, through comparison of all integration methods and the exact solution, we can see that RK4 is most accurate; the reason it is most accurate is................................
~~~

~~~
References

Almodovar, Alex. Multiple conversations (both in-person and via email) regarding both Part I and Part II, 9-27FEB17. Alex provided guidance in how to fork repositories, and offered troubleshooting advice and guidance for running code for Part I
integration solutions; generally compared my solution to his in order to see if
I was on the right track.

Kider, Joseph.  Conversations via email and during office hours on 22-27FEB17 regarding errors compiling code, printing functions, and general help determining if      solution was correct.
~~~
##Part 2.

a. Forward Euler, midpoint integration, and RK4.  Implement JelloMesh::EulerIntegration(), 
JelloMesh::MidpointIntegration(), and JelloMesh::RK4Integration()

ANS: See jelloMesh.cpp; essentially took the Lecture6 Solution and integrated into jellowMesh.cpp from lines
488-605.

b. Implement spring forces in JelloMesh::ComputerForces(ParticleGrid&grid), find good spring constants

c. Test collisions/contacts with ground and cylyndrical objects in scene.  Look at 
JelloMesh::CheckForCollisions(ParticleGrid&grid) and implement JelloMesh::CylinderCollision() and 
JelloMesh::FloorCollision()

d. Collision and penetration response.  Implement JelloMesh::ResolveContacts(ParticleGrid&grid) and
JelloMesh::ResolveCollisions(ParticleGrid&grid)

e. Extra springs that simulate shear/bending resistance.  Modify JelloMesh::InitJellowMesh()

f. Implement two extra features - X and Y


##Part 3
1.What is the effect of Ks and Kd parameters on the jello?

~~~
ANS: 
Ks is the spring constant and Kd is the dampening constant; therefore, they are
two opposing forces that come into effect when the jello hits the surface.
~~~


2.What are the benefits and the drawbacks of the collision system used here?
What are some different ways in which it could be improved?

~~~
ANS: 
The benefits are X...the drawbacks are Y.  The system could be improved by
the utilization of better integration methods beyond RK4 to give a more realistic
simulation; granted, more realism is probably not needed given the nature of this
project.
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
Fairly; seems a bit.......RK4?
~~~

5.How would you model and simulate water (in terms of continuous simulation)?

~~~
ANS: 
Likely would use particle to simulate the water molecules; we would have to delve
into the laws of physics as they relate to water and how it moves and what can cause that movement (Author Unknown, Date Unknown).
~~~

| RK1 | RK2 | RK4 | Exact |
| --- | --- | --- | ----- |
| 0.0 | 0.0 | 0.0 | 0.0 |
| 0.5 | ttt | ttt | ttt |

~~~
References

Almodovar, Alex. Multiple conversations (both in-person and via email) regarding both Part I and Part II, 9-27FEB17. Alex provided guidance in how to fork repositories, and offered troubleshooting advice and guidance for running code for Part I
integration solutions; generally compared my solution to his in order to see if
I was on the right track.

Baraff, D., Witkin, A., and Kass, M.  (2003).  Untangling Cloth.  Pixar Animation   Studios.  Retrieved from http://graphics.pixar.com/library/UntanglingCloth/paper.pdf

Kider, Joseph.  Conversations via email and during office hours on 22-27FEB17 regarding errors compiling code, printing functions, and general help determining if      solution was correct.

Author Unknown. (Date Unknown).  Mass-Spring Systems PowerPoint.  Rensselaer          Polytechnic Institute.  Retrieved from https://www.cs.rpi.edu/~cutler/classes/advancedgraphics/S09/lectures/06_mass_spring_systems.pdf.
~~~

