//walk.h
#ifndef WALK_H_
#define WALK_H_
#include"walkbehavior.h"
#include<iostream>
class Walk :public WalkBehavior {
public:
	void walk() {
		std::cout << "\tWalking...\n";
	}
};
#endif 