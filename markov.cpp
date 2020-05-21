#include "markov.hpp"

MarkovChain::MarkovChain(int s){
	states = s;
	step = 1;
	cout << "Transition Matrix: " << endl;
	static Matrix TM(states, states, true);
	TransitionMatrix = &TM;
	if(!is_TM_valid()){
		throw runtime_error("is_TM_valid: One of the rows sum isn't 1");
	}
	vector<string> st(states,"null");
	string aux;
	for(int i = 0; i < states; i++){
		cout << "Insert name of state " << i+1 << endl;
		cin >> aux;
		st[i] = aux;
	}
	statesVector = st;
	cout << "Transition Matrix is valid" << endl;
}

void MarkovChain::DoStep(int nsteps){
	step += nsteps;
	for(int i = 0; i < nsteps; i++){
		*TransitionMatrix = *TransitionMatrix * *TransitionMatrix;
	}
}

	

void MarkovChain::FindSteadyVector(Matrix initial_dist){
	static Matrix dis_n = initial_dist;
	while(!(dis_n == getDistribution(dis_n))){
		dis_n = getDistribution(dis_n);
	}
	SteadyVector = &dis_n;
}
	
bool MarkovChain::is_TM_valid(){
	for(int i = 1; i <= states; i++){
		if(TransitionMatrix->sum_elements_row(i) != 1){
			return false;
		}
	}
	return true;
}

double MarkovChain::getProb(int si, int sj){
	return TransitionMatrix->get_element(si,sj);
}

Matrix MarkovChain::getDistribution(Matrix x){
	Matrix Q = TransitionMatrix->transpose();
	Matrix x_n = Q * x;
	return x_n;
}

Matrix MarkovChain::getTM(){
	return *TransitionMatrix;
}

Matrix MarkovChain::getSV(){
	return *SteadyVector;
}

vector<string> MarkovChain::getStateVector(){
	return statesVector;
}

void MarkovChain::printTM(){
	cout << *TransitionMatrix << endl;
}


void MarkovChain::printSV(){
	cout << *SteadyVector << endl;
}

int MarkovChain::getCurrentStep(){
	return step;
}

void UpdateEvent(Event &e){
	double r=((double) rand())/(RAND_MAX);
	for(int i = 0; i < e.probabilities.size(); i++){
		if(r <= e.probabilities[i]){
			e.state = e.states[i];
			return;
		}
		r -= e.probabilities[i];
	}
}

void GetProbabilitiesEvent(Event &e, MarkovChain m){
	int aux_id;
	e.states = m.getStateVector();
	for(int i = 0; i < e.states.size(); i++){
		if(e.state == e.states[i])
			aux_id = i;
	}
	Matrix tm = m.getTM();
	cout << aux_id << endl;
	e.probabilities = tm.get_row(aux_id+1);
}