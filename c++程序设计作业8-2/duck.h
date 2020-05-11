//duck.h
#ifndef DUCK_H_
#define DUCK_H_
#include<string>
#include<iostream>
#include"FlyBehavior.h"
#include"QuackBehavior.h"
#include"Quack.h"
#include"FlyWithWings.h"
class duck{
protected:
	float _weight;
	std::string _name;
	FlyBehavior * flyBehavior;
	QuackBehavior * quackBehavior;
public:
	duck(const char * name, float w) :
		_name(name), _weight(w) {
		// quackBehavior=new Quack();
		// flyBehavior=new FlyWithWings();
		std::cout << "Duck " << name << " is born\n";
	}
	void display();
	void swim();
	void performQuack(){quackBehavior->quack();};
	void performFly(){flyBehavior->fly();};
	void setFlyBehavior(FlyBehavior *fb){flyBehavior=fb;};
	void setQuackBehavior(QuackBehavior *qb){quackBehavior=qb;};
};
#endif 
