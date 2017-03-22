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


// Hint: Set N - number of simulations low until you have it working
//       Then set it much much higher, and run in release mode so its faster

int main() {

	SetTransitionMatrix();

	// Print Results to File
	std::ofstream myfile;
	myfile.open("markov_results.txt");

	int start = 0;

	//simulate discrete time Markov Chain
	unsigned int N = 50;
	std::map<int, int> hist;
	std::vector<int> discreteMC;
	for (unsigned int i = 0; i < N; ++i) {
		
		//TODO (add DTMC, and histogram lines.)
		 /*int main() {
			//SIMULATE DISCRETE TIME MARKOV CHAIN
			std::vector< std::vector<double> > matrix(3, std::vector<double>(3)); //initializes a 3x3 matrix with zeros

																				  //set transition matrix
			matrix[0][1] = 1;
			matrix[1][2] = 1;
			matrix[2][0] = 1;

			int steps = 10;
			int start = 0;
			double T = 8.5;

			//simulate discrete time Markov Chain
			//unsigned int N = 100000;
			std::map<int, int> hist;
	        */

			std::vector<int> discreteMC;
			//for (unsigned int i = 0; i < N; ++i){
			discreteMC = DTMC(matrix, steps, start);
			++hist[std::round(discreteMC.back())];

			//  }
			//Returns an array with the states at each step of the discrete-time Markov Chain
			//The number of transitions is given by steps. The initial state is given by start 
			//(the states are indexed from 0 to n-1 where n is the number of arrays in transMatrix).

			for (auto elem : discreteMC)
				std::cout << elem << std::endl;

			std::cout << std::endl;

			//  for (auto p : hist)
			//	  std::cout << p.first << "\t" << p.second << std::endl;


			std::cout << std::endl << "End State is: " << discreteMC.back() << std::endl << std::endl;

		// Code if you wanted to print out results at each step
		//for (auto elem : discreteMC)
		//	std::cout << elem << std::endl;

	}
	//Returns an array discreteMC with the states at each step of the discrete-time Markov Chain
	//The number of transitions is given by steps. The initial state is given by start 
	//(the states are indexed from 0 to n-1 where n is the number of arrays in transMatrix).
	//hist is the histogram 


	// (double)p.second / N    - (decimal) percentage.
	for (auto p : hist) {
		std::cout << p.first << "\t" << (double)p.second / N << std::endl;
	}

	myfile.close();

	return 1;
}