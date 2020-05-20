//redheadduck.h
#ifndef REDHEADDUCK_H_
#define REDHEADDUCK_H_
#include"duck.h"
#include"quackbehavior.h"
#include"flybehavior.h"
#include<iostream>
class RedheadDuck :public Duck {
public:
	RedheadDuck(QuackBehavior * qb = NULL, FlyBehavior * fb = NULL) :Duck(qb, fb) {}
	void display() {
		std::cout << "\tRedhead duck is handsome\n";
	}
};
#endif 