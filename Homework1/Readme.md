#CharlieTimm
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


*Utilized Wolfram Alpha; by inputting y'(x)=y-1/2*e^(x/2)*sin(5x)+5e^(x/2)*cos(5x) , y(0)=0

b. Translate mathematical formulas into df and exact functions.

ANS:
Compute the dy/dx
*/
double df(double x, double y)            //function for defining dy/dx
{
    return y - (1.0 / 2.0)*exp(x / 2.0)*sin(5.0 * x) + 5.0 * exp(x / 2.0)*cos(5.0 * x);
}

~~~
/*
Compute the exact answer
*/
double exact(double x)            //function for defining dy/dx
{
    return exp(x / 2.0)*sin(5.0 * x);
}
~~~

*Utilized Lecture6 Solution; could only get the answer to flash on screen for about half a second

c. Run 3 numerical integration solutions: RK1, RK2, and RK4 to generate numerical and exact values; use h=.1 for x = <0.0,
 10.0>. Graph results and exact solution.

| RK1 | RK2 | RK4 | Exact |
| --- | --- | --- | ----- |
| 0.0 | 0.0 | 0.0 | 0.0 |
| 0.5 | ttt | ttt | ttt |




*Use the helloworld from Lecture6 Solution?  How to input H values? H = .1 -> 10.0 = 100?
How to define?  Use same program as for answer b?

d. Plot error percentages for RK1, RK2, and RK4 in another graph.  Error defined by %error = |exact-apprx|/exact.

*Can use error percentage in lines 30-34; again, can't see print...

e. Vary step size h = n where you define three n values for x = <0.0, 10.0>. Plot results for RK4 with 3 different n values 
with exact solutions. Plot the error rate.

*Could use 0, 5, 10 for H and then plot/show error percentage; again, print function.

f. Analyze results: 1. Describe how varying integration method changes accuracy, 2. What happens as you increase x value
to the accuracy, 3. How does varying step size effect accuracy, 4. Which method is most accurage and why (what is taken into
account in the solution). 

*1. From class, in general as we go from RK1-RK4 the accuracy increases; 
*2. Increasing X value should increase the accuracy, as we're taking more slices...
*3. Kind of related to 2, the more steps we take the better, but the further apart they are
the more errors we'll have
*4. RK4 is most accurate; refer to the solution graph


References
Almodovar, Alex. Multiple conversations (both in-person and via email) regarding both Part I and Part II, 9-21FEB17. 
Alex provided guidance in how to fork repositories, offered troubleshooting advice and guidance for running code for Part I
integration solutions...allowed to view/compare my solution to his.   



Part 2.

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
