//squeak
#ifndef SQUEAK_H_
#define SQUEAK_H_
#include"quackbehavior.h"
#include<iostream>
class Squeak :public QuackBehavior {
public:
	void quack() {
		std::cout << "\tJi ji ji...\n";
	}
};
#endif 