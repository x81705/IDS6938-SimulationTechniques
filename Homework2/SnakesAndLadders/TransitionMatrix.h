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

void ModifyTransitionMatrix() //Sarah helped with formulation of this function

{
	// ladders from 4 to 20
	TransitionMatrix(0, 3) = 0;		TransitionMatrix(0, 19) = prob;

	TransitionMatrix(1, 3) = 0;		TransitionMatrix(1, 19) = prob;

	TransitionMatrix(2, 3) = 0;		TransitionMatrix(2, 19) = prob;

	// ladders from 16 to 38

	TransitionMatrix(9, 15) = 0;		TransitionMatrix(9, 37) = prob;

	TransitionMatrix(10, 15) = 0;		TransitionMatrix(10, 37) = prob;

	TransitionMatrix(11, 15) = 0;		TransitionMatrix(11, 37) = prob;

	TransitionMatrix(12, 15) = 0;		TransitionMatrix(12, 37) = prob;

	TransitionMatrix(13, 15) = 0;		TransitionMatrix(13, 37) = prob;

	TransitionMatrix(14, 15) = 0;		TransitionMatrix(14, 37) = prob;

	// ladders from 23 to 43

	TransitionMatrix(16, 22) = 0;		TransitionMatrix(16, 42) = prob;

	TransitionMatrix(17, 22) = 0;		TransitionMatrix(17, 42) = prob;

	TransitionMatrix(18, 22) = 0;		TransitionMatrix(18, 42) = prob;

	TransitionMatrix(19, 22) = 0;		TransitionMatrix(19, 42) = prob;

	TransitionMatrix(20, 22) = 0;		TransitionMatrix(20, 42) = prob;

	TransitionMatrix(21, 22) = 0;		TransitionMatrix(21, 42) = prob;

	// ladders from 26 to 65

	TransitionMatrix(19, 25) = 0;		TransitionMatrix(19, 64) = prob;

	TransitionMatrix(20, 25) = 0;		TransitionMatrix(20, 64) = prob;

	TransitionMatrix(21, 25) = 0;		TransitionMatrix(21, 64) = prob;

	TransitionMatrix(22, 25) = 0;		TransitionMatrix(22, 64) = prob;

	TransitionMatrix(23, 25) = 0;		TransitionMatrix(23, 64) = prob;

	TransitionMatrix(24, 22) = 0;		TransitionMatrix(24, 64) = prob;

	// ladders from 42 to 74

	TransitionMatrix(36, 41) = 0;		TransitionMatrix(36, 74) = prob;

	TransitionMatrix(37, 41) = 0;		TransitionMatrix(37, 74) = prob;

	TransitionMatrix(38, 41) = 0;		TransitionMatrix(38, 74) = prob;

	TransitionMatrix(39, 41) = 0;		TransitionMatrix(39, 74) = prob;

	TransitionMatrix(40, 41) = 0;		TransitionMatrix(40, 74) = prob;

	TransitionMatrix(41, 41) = 0;		TransitionMatrix(41, 74) = prob;

	// ladders from 54 to 75

	TransitionMatrix(47, 53) = 0;		TransitionMatrix(47, 74) = prob;

	TransitionMatrix(48, 53) = 0;		TransitionMatrix(48, 74) = prob;

	TransitionMatrix(49, 53) = 0;		TransitionMatrix(49, 74) = prob;

	TransitionMatrix(50, 53) = 0;		TransitionMatrix(50, 74) = prob;

	TransitionMatrix(51, 53) = 0;		TransitionMatrix(51, 74) = prob;

	TransitionMatrix(52, 53) = 0;		TransitionMatrix(52, 74) = prob;

	// ladders from 64 to 87

	TransitionMatrix(58, 63) = 0;		TransitionMatrix(58, 86) = prob;

	TransitionMatrix(59, 63) = 0;		TransitionMatrix(59, 86) = prob;

	TransitionMatrix(60, 63) = 0;		TransitionMatrix(60, 86) = prob;

	TransitionMatrix(61, 63) = 0;		TransitionMatrix(61, 86) = prob;

	TransitionMatrix(62, 63) = 0;		TransitionMatrix(62, 86) = prob;

	TransitionMatrix(63, 63) = 0;		TransitionMatrix(63, 86) = prob;

	// ladders from 77 to 92

	TransitionMatrix(70, 76) = 0;		TransitionMatrix(70, 91) = prob;

	TransitionMatrix(71, 76) = 0;		TransitionMatrix(71, 91) = prob;

	TransitionMatrix(72, 76) = 0;		TransitionMatrix(72, 91) = prob;

	TransitionMatrix(73, 76) = 0;		TransitionMatrix(73, 91) = prob;

	TransitionMatrix(74, 76) = 0;		TransitionMatrix(74, 91) = prob;

	TransitionMatrix(75, 76) = 0;		TransitionMatrix(75, 91) = prob;

	// ladders from 85 to 99

	TransitionMatrix(78, 84) = 0;		TransitionMatrix(78, 98) = prob;

	TransitionMatrix(79, 84) = 0;		TransitionMatrix(79, 98) = prob;

	TransitionMatrix(80, 84) = 0;		TransitionMatrix(80, 98) = prob;

	TransitionMatrix(81, 84) = 0;		TransitionMatrix(81, 98) = prob;

	TransitionMatrix(82, 84) = 0;		TransitionMatrix(82, 98) = prob;

	TransitionMatrix(83, 84) = 0;		TransitionMatrix(83, 98) = prob;

	//SNAKES - 12 to 8

	TransitionMatrix(5, 11) = 0;		TransitionMatrix(5, 7) = prob * 2;

	TransitionMatrix(6, 11) = 0;		TransitionMatrix(6, 7) = prob * 2;

	TransitionMatrix(7, 11) = 0;		TransitionMatrix(7, 7) = prob;

	TransitionMatrix(8, 11) = 0;		TransitionMatrix(8, 7) = prob;

	TransitionMatrix(9, 11) = 0;		TransitionMatrix(9, 7) = prob;

	TransitionMatrix(10, 11) = 0;		TransitionMatrix(10, 7) = prob;

	//SNAKES - 19-14

	TransitionMatrix(12, 18) = 0;		TransitionMatrix(12, 13) = prob * 2;

	TransitionMatrix(13, 18) = 0;		TransitionMatrix(13, 13) = prob;

	TransitionMatrix(14, 18) = 0;		TransitionMatrix(14, 13) = prob;

	TransitionMatrix(15, 18) = 0;		TransitionMatrix(15, 13) = prob;

	TransitionMatrix(16, 18) = 0;		TransitionMatrix(16, 13) = prob;

	TransitionMatrix(17, 18) = 0;		TransitionMatrix(17, 13) = prob;

	//SNAKES - 29-13

	TransitionMatrix(22, 28) = 0;		TransitionMatrix(22, 12) = prob;

	TransitionMatrix(23, 28) = 0;		TransitionMatrix(23, 12) = prob;

	TransitionMatrix(24, 28) = 0;		TransitionMatrix(24, 12) = prob;

	TransitionMatrix(25, 28) = 0;		TransitionMatrix(25, 12) = prob;

	TransitionMatrix(26, 28) = 0;		TransitionMatrix(26, 12) = prob;

	TransitionMatrix(27, 28) = 0;		TransitionMatrix(27, 12) = prob;

	//SNAKES - 37-35

	TransitionMatrix(30, 36) = 0;		TransitionMatrix(30, 34) = prob * 2;

	TransitionMatrix(31, 36) = 0;		TransitionMatrix(31, 34) = prob * 2;

	TransitionMatrix(32, 36) = 0;		TransitionMatrix(32, 34) = prob * 2;

	TransitionMatrix(33, 36) = 0;		TransitionMatrix(33, 34) = prob * 2;

	TransitionMatrix(34, 36) = 0;		TransitionMatrix(34, 34) = prob;

	TransitionMatrix(35, 36) = 0;		TransitionMatrix(35, 34) = prob;

	//SNAKES - 78-17

	TransitionMatrix(71, 77) = 0;		TransitionMatrix(71, 16) = prob;

	TransitionMatrix(72, 77) = 0;		TransitionMatrix(72, 16) = prob;

	TransitionMatrix(73, 77) = 0;		TransitionMatrix(73, 16) = prob;

	TransitionMatrix(74, 77) = 0;		TransitionMatrix(74, 16) = prob;

	TransitionMatrix(75, 77) = 0;		TransitionMatrix(75, 16) = prob;

	TransitionMatrix(76, 77) = 0;		TransitionMatrix(76, 16) = prob;

	//SNAKES - 48-27

	TransitionMatrix(41, 47) = 0;		TransitionMatrix(41, 26) = prob;

	TransitionMatrix(42, 47) = 0;		TransitionMatrix(42, 26) = prob;

	TransitionMatrix(43, 47) = 0;		TransitionMatrix(43, 26) = prob;

	TransitionMatrix(44, 47) = 0;		TransitionMatrix(44, 26) = prob;

	TransitionMatrix(45, 47) = 0;		TransitionMatrix(45, 26) = prob;

	TransitionMatrix(46, 47) = 0;		TransitionMatrix(46, 26) = prob;

	//SNAKES - 84-40

	TransitionMatrix(77, 83) = 0;		TransitionMatrix(77, 39) = prob;

	TransitionMatrix(78, 83) = 0;		TransitionMatrix(78, 39) = prob;

	TransitionMatrix(79, 83) = 0;		TransitionMatrix(79, 39) = prob;

	TransitionMatrix(80, 83) = 0;		TransitionMatrix(80, 39) = prob;

	TransitionMatrix(81, 83) = 0;		TransitionMatrix(81, 39) = prob;

	TransitionMatrix(82, 83) = 0;		TransitionMatrix(82, 39) = prob;

	//SNAKES - 93-76

	TransitionMatrix(86, 92) = 0;		TransitionMatrix(86, 75) = prob;

	TransitionMatrix(87, 92) = 0;		TransitionMatrix(87, 75) = prob;

	TransitionMatrix(88, 92) = 0;		TransitionMatrix(88, 75) = prob;

	TransitionMatrix(89, 92) = 0;		TransitionMatrix(89, 75) = prob;

	TransitionMatrix(90, 92) = 0;		TransitionMatrix(90, 75) = prob;

	TransitionMatrix(91, 92) = 0;		TransitionMatrix(91, 75) = prob;

	//SNAKES - 100-71

	TransitionMatrix(93, 99) = 0;		TransitionMatrix(93, 70) = prob;

	TransitionMatrix(94, 99) = 0;		TransitionMatrix(94, 70) = prob;

	TransitionMatrix(95, 99) = 0;		TransitionMatrix(95, 70) = prob;

	TransitionMatrix(96, 99) = 0;		TransitionMatrix(96, 70) = prob;

	TransitionMatrix(97, 99) = 0;		TransitionMatrix(97, 70) = prob;

	TransitionMatrix(98, 99) = 0;		TransitionMatrix(98, 70) = prob;

}