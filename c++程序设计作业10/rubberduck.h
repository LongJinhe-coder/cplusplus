//rubberduck.h
#ifndef RUBBERDUCK_H_
#define RUBBERDUCK_H_
#include"duck.h"
#include"quackbehavior.h"
#include<iostream>
class RubberDuck :public Duck {
public:
	RubberDuck(QuackBehavior * qb) :Duck(qb, NULL) {}
	void display() {
		std::cout << "\tRubber duck is handsome\n";
	}
};
#endif 