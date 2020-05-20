//quack.h
#ifndef QUACK_H_
#define QUACK_H_
#include"quackbehavior.h"
#include<iostream>
class Quack :public QuackBehavior {
public:
	void quack() {
		std::cout << "\tGa ga ga...\n";
	}
};
#endif 