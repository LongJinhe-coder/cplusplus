#pragma once
#include "state.h"

class concreteState3: public state{
private:
	bool _state3;
public:
	concreteState3(bool s): _state3(s){};
	concreteState3(){};

	void setState3(bool s){
	_state3 = s;
}

bool getState3(){
	return _state3;
}
};


