int size = 10;  //TODO
Eigen::MatrixXf TransitionMatrix(size, size);
Eigen::VectorXf v(size);

unsigned int ROLLS = 0; //TODO

double prob = 1.0/6.0 ;  //TODO

//Std:cout << SetTransitionMatrix << std :: end]; //Added


void SetTransitionMatrix()
{
	TransitionMatrix.setZero();

	//TODO
	For(int i = 0; i < TransitionMatrix.rows() - 6; i++); //Added from class
	TransitionMatrix(i, i + 1) = prob; //Added from class

	//SetTransitionMatrix



}