//flywithwings.h
#ifndef FLYWITHWINGS_H_
#define FLYWITHWINGS_H_
#include"flybehavior.h"
#include<iostream>
class FlyWithWings :public FlyBehavior {
public:
	void fly() {
		std::cout << "\tFlying with wings\n";
	}
};
#endif