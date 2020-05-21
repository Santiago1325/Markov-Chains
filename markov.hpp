#ifndef __MarkovChain__hpp
#define __MarkovChain__hpp

#include "matrix.hpp"
#include <string>

class MarkovChain{
private:
	int step;
	int states;
	Matrix *TransitionMatrix;
	Matrix *SteadyVector;
	vector<string> statesVector;


public:
	MarkovChain(int s);
	~MarkovChain(){};
	void DoStep(int nsteps);
	void FindSteadyVector(Matrix initial_dist);
	void printTM();
	void printSV();
	double getProb(int si, int sj);
	bool is_TM_valid();
	Matrix getDistribution(Matrix x);
	Matrix getTM();
	Matrix getSV();
	vector<string> getStateVector();
};

struct Event{
	string state;
	vector<string> states;
	vector<double> probabilities;
};

void UpdateEvent(Event &e);

void GetProbabilitiesEvent(Event &e, MarkovChain m);




#endif