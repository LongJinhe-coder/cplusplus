//duck.h
#ifndef DUCK_H_
#define DUCK_H_
#include"flybehavior.h"
#include"quackbehavior.h"
#include"walkbehavior.h"
#include<cstdlib>
class Duck {
protected:
	QuackBehavior * _qb;
	FlyBehavior * _fb;
    WalkBehavior * _wb;
public:
	Duck(QuackBehavior * qb = NULL, FlyBehavior * fb = NULL, WalkBehavior * wb = NULL):_qb(qb),_fb(fb),_wb(wb){}
	virtual void display();
	void swim();
	void setQuackBehavior(QuackBehavior * qb) {
		_qb = qb;
	};
	void setFlyBehavior(FlyBehavior *fb) {
		_fb = fb;
	};
	void setWalkBehavior(WalkBehavior *wb) {
		_wb = wb;
	};
	void fly();			//i.e. performFly()
	void quack();		//i.e. performQuack()
	void walk();		//i.e. performWalk()
	virtual ~Duck() {
		if (_qb) delete _qb;
		if (_fb) delete _fb;
		if (_wb) delete _wb;
	}
};
#endif 
