#pragma once
#include "state.h"

class concreteState1: public state{
private:
	int _state1;
public:
	concreteState1(int s): _state1(s){};
	concreteState1(){};

	void setState1(int s){
	_state1 = s;
}

int getState1(){
	return _state1;
}
};


