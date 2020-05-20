//flywithengine.h
#ifndef FLYWITHENGINE_H_
#define FLYWITHENGINE_H_
#include"flybehavior.h"
#include<iostream>
class FlyWithEngine :public FlyBehavior {
public:
	void fly() {
		std::cout << "\tFlying with engine\n";
	}
};
#endif