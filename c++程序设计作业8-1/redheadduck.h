//redheadduck.h
#ifndef READHEADDUCK_H_
#define READHEADDUCK_H_
#include"duck.h"
#include"flyable.h"
#include"quackable.h"
class redheadduck :public duck,public flyable,public quackable {
public:
	redheadduck(const char * name, float w) :
		duck(name, w) {}
	void display();	//to overwrite
};
#endif 
