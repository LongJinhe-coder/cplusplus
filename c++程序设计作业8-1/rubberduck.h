//rubberduck.h
#ifndef RUBBERDUCK_H_
#define RUBBERDUCK_H_
#include"duck.h"
#include"quackable.h"
class rubberduck :public duck,public quackable{
public:
	rubberduck(const char * name, float w) :
		duck(name, w) {}
	    void display(){
            std::cout << '\t' << _name << " is a rubberduck, weighted " << _weight << " KG\n";
        }
        
};
#endif 
