#include "matrix.hpp"
#include "markov.hpp"
#include <stdlib.h>


int main(){

	MarkovChain Elevator(3);
	Elevator.printTM();

	Event Floor;
	Floor.state = "Floor_1";
	cout <<"State: " << Floor.state << endl;
	for(int i = 0; i < 10000; i++){
		GetProbabilitiesEvent(Floor, Elevator);
		UpdateEvent(Floor);
		cout << "State: " << Floor.state << endl;
	}


	return 0;

}