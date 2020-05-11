//rubberduck.h
#ifndef RUBBERDUCK_H_
#define RUBBERDUCK_H_
#include "duck.h"
#include"FlyNoWay.h"
#include"Squack.h"
class rubberduck : public duck
{
public:
	rubberduck(const char *name, float w) : duck(name, w) {
		quackBehavior = new Squack();
		flyBehavior = new FlyNoWay();
	}
	void display()
	{
		std::cout << '\t' << _name << " is a rubberduck, weighted " << _weight << " KG\n";
	}
};
#endif
