//robotduck.h
#ifndef ROBOTDUCK_H_
#define ROBOTDUCK_H_
#include"duck.h"
#include"quackbehavior.h"
#include"flybehavior.h"
#include"walkbehavior.h"
#include<iostream>
class RobotDuck :public Duck {
public:
	RobotDuck(QuackBehavior * qb = NULL,FlyBehavior * fb = NULL,WalkBehavior * wb = NULL) :Duck(qb,fb,wb) {}
	void display() {
		std::cout << "\tRobot duck is handsome\n";
	}
};
#endif 