int size = 101;  //TODO
Eigen::MatrixXf TransitionMatrix(size, size);
Eigen::VectorXf v(size);

unsigned int ROLLS = 50; //TODO

double prob = 1.0/6.0 ;  //TODO

//Std:cout << SetTransitionMatrix << std :: end]; //Added - maybe put at the end //


void SetTransitionMatrix()
{
	TransitionMatrix.setZero();

	//TODO
	for (int i = 0; i < TransitionMatrix.rows() - 6; i++) //Added from class
	{
	TransitionMatrix(i, i + 1) = prob; //Added from class, and helped from William during Study Period
	TransitionMatrix(i, i + 2) = prob;
	TransitionMatrix(i, i + 3) = prob;
	TransitionMatrix(i, i + 4) = prob;
	TransitionMatrix(i, i + 5) = prob; 
	TransitionMatrix(i, i + 6) = prob;
    }
	//SetTransitionMatrix
	//TransitionMatrix(95, 100) = prob*2;  //keep going, increase to 96,97, - prob, 3, 4 - through 100 and prob*6
	//William helped with the below code; I had only inputted (95, 100) = prob*2, (96, 100) = prob*3 etc;

	TransitionMatrix(95, 96) = prob;
	TransitionMatrix(95, 97) = prob;
	TransitionMatrix(95, 98) = prob;
	TransitionMatrix(95, 99) = prob;
	TransitionMatrix(95, 100) = prob * 2;
	
	TransitionMatrix(96, 97) = prob;
	TransitionMatrix(96, 98) = prob;
	TransitionMatrix(96, 99) = prob;
	TransitionMatrix(96, 100) = prob * 3;

	TransitionMatrix(97, 98) = prob;
	TransitionMatrix(97, 99) = prob;
	TransitionMatrix(97, 100) = prob * 4;

	TransitionMatrix(98, 99) = prob;
	TransitionMatrix(98, 100) = prob * 5;
	
	TransitionMatrix(99, 100) = 1;

	TransitionMatrix(100, 100) = 1;
	
	std::cout << TransitionMatrix << std::endl;
	exit(1);
	
}