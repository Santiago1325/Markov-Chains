#include "matrix.hpp"
#include "markov.hpp"


int main(){

	MarkovChain test(2);
	test.printTM();
	//test.DoStep(1);
	//test.printTM();
	//test.DoStep(2);
	//test.printTM();
	//test.DoStep(2);
	//test.printTM();
	Event Clima;
	Clima.state = "Sun";
	cout <<"State: " << Clima.state << endl;
	for(int i = 0; i < 1000; i++){
		GetProbabilitiesEvent(Clima, test);
		UpdateEvent(Clima);
		cout << "State: " << Clima.state << endl;
	}


	return 0;

}