#include "matrix.hpp"
#include "markov.hpp"
#include <stdlib.h>


int main(){

	MarkovChain CarDistribution(3);
	CarDistribution.printTM();

	Matrix x(3,1,true);
	Matrix xn = x;
	cout << "X0:" << endl;
	cout << xn << endl;
	for(int i = 1; i <= 15; i++){
		cout << "X" << i << ":" << endl;
		xn = CarDistribution.getDistribution(xn);
		cout << xn << endl;
	}

	cout << "Steady state vector" << endl;
	CarDistribution.FindSteadyVector(x);
	Matrix ssv = CarDistribution.getSV();
	cout << ssv << endl;

	return 0;

}