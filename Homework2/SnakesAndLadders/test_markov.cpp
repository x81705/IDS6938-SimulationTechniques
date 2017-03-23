#include <iostream>
#include <functional>   
#include <numeric> 
#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <Eigen\dense>

#include "markov.h"
#include "TransitionMatrix.h"

int main(){

	SetTransitionMatrix();

	//Output Vector
	v.setZero();
	v(0) = 1.0;

	// Print Results to File
	std::ofstream myfile;
	myfile.open("markov_results.txt");

	
   // TODO add Markov vector - Matrix multiplication - Added all below

	std::vector<int> DTMC(Eigen::MatrixXf trans, int steps, int start) { //Added from Markov.cpp
		//random generator
		std::random_device rd;
		std::mt19937 gen(rd());
		//initialize state vector
		std::vector<int> myVec(steps + 1);
		myVec[0] = start;
		//initialize counter variables
		int count;
		double sum;
		double U;

		//for each step, simulate the next step from the current state row
		for (int i = 0; i<steps; i++) {
			count = 0;
			sum = 0;
			U = std::generate_canonical<double, 10>(gen);
			while (sum < U) {
				sum += trans(myVec[i], count);
				if (sum > U) {
					myVec[i + 1] = count;
				}
				count++;
			}
		}
		return myVec;
	} //Added


	For(int i = 0; i < TransitionMatrix.rows() - 6; i++); //Added from class
	TransitionMatrix(i, i + 1) = prob;
	std::cout <<  v << std::endl;

	myfile << v << std::endl;  //this is just a sample, becareful how you print to file so you can mine useful stats
	
	myfile.close();


  return 1;
}