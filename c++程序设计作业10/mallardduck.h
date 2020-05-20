//mallardduck.h
#ifndef MALLARDDUCK_H_
#define MALLARDDUCK_H_
#include"duck.h"
#include"quackbehavior.h"
#include"flybehavior.h"
#include<iostream>
class MallardDuck :public Duck {
public:
	MallardDuck(QuackBehavior * qb = NULL,FlyBehavior * fb = NULL) :Duck(qb,fb) {}
	void display() {
		std::cout << "\tMallard duck is handsome\n";
	}
};
#endif 