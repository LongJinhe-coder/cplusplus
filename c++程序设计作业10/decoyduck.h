//decoy.h
#ifndef DECOYDUCK_H_
#define DECOYDUCK_H_
#include"duck.h"
#include<iostream>
class DecoyDuck:public Duck {
public:
	DecoyDuck():Duck(NULL, NULL) {}
	void display() {
		std::cout << "\tDecoy duck is handsome\n";
	}
};
#endif 