//redheadduck.h
#ifndef READHEADDUCK_H_
#define READHEADDUCK_H_
#include"duck.h"
#include"FlyWithWings.h"
#include"Quack.h"
class redheadduck :public duck{
public:
	redheadduck(const char * name, float w) :duck(name, w) {
		quackBehavior = new Quack();
		flyBehavior = new FlyWithWings();
	}
	void display(){
		std::cout << '\t' << _name << "\'s head is red, weighted " << _weight << " KG\n";
	}
};
#endif 
