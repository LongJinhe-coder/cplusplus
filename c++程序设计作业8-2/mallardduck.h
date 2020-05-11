//mallardduck.h
#ifndef MALLARDDUCK_H_
#define MALLARDDUCK_H_
#include"duck.h"
#include"FlyWithWings.h"
#include"Quack.h"
class mallardduck : public duck
{
public:
	mallardduck(const char *name, float w) : duck(name, w) {
		quackBehavior = new Quack();
		flyBehavior = new FlyWithWings();
	}
	void display()
	{
		std::cout << '\t' << _name << " is a rubberduck, weighted " << _weight << " KG\n";
	}
};
#endif
