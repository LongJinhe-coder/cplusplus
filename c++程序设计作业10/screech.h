//screech.h
#ifndef SCREECH_H_
#define SCREECH_H_
#include"quackbehavior.h"
#include<iostream>
class Screech :public QuackBehavior {
public:
	void quack() {
		std::cout << "\tscreech ...\n";
	}
};
#endif 