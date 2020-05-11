//decoyduck.h
#ifndef DECOYDUCK_H_
#define DECOYRDUCK_H_
#include "duck.h"
#include"FlyNoWay.h"
#include"MuteQuack.h"
class decoyduck : public duck
{
public:
    decoyduck(const char *name, float w) : duck(name, w) {
        quackBehavior = new MuteQuack();
		flyBehavior = new FlyNoWay();
    }
    void display()
    {
        std::cout << '\t' << _name << " is a decoyduck, weighted " << _weight << " KG\n";
    }
};
#endif
