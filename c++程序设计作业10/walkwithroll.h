//walkwithroll.h
#ifndef WALKWITHROLL_H_
#define WALKWITHROLL_H_
#include"walkbehavior.h"
#include<iostream>
class WalkWithRoll :public WalkBehavior {
public:
	void walk() {
		std::cout << "\tWalking with roll\n";
	}
};
#endif 