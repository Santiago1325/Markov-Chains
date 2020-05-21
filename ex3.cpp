#include "matrix.hpp"
#include "markov.hpp"
#include <stdlib.h>


int main(){

	MarkovChain WeatherChange(3);
	cout << "Step 1:" << endl;
	WeatherChange.printTM();
	int nsteps;
	cout << "Insert number of steps: ";
	cin >> nsteps;
	for(int i = 1; i <= nsteps; i++){
		WeatherChange.DoStep(1);
		cout << "Setp: " << WeatherChange.getCurrentStep() << endl;
		WeatherChange.printTM(); 
	}
	return 0;

}