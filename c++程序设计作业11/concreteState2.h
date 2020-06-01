#pragma once
#include "state.h"

class concreteState2: public state{
private:
	char* _state2;
public:
	concreteState2(char* s): _state2(s){};
	concreteState2(){};

	void setState2(char* s){
	_state2 = s;
}

char* getState2(){
	return _state2;
}
};


