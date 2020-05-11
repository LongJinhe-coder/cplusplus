//mallarduck.h
#ifndef MALLARDDUCK_H_
#define MALLARDDUCK_H_
#include"duck.h"
#include"flyable.h"
#include"quackable.h"
class mallardduck:public duck,public flyable,public quackable {
public:
	mallardduck(const char * name, float w):
		duck(name, w){}
	void display();	//to overwrite
};
#endif 