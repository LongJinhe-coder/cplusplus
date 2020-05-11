//decoyduck.h
#ifndef DECOYDUCK_H_
#define DECOYRDUCK_H_
#include"duck.h"
class decoyduck :public duck{
public:
	decoyduck(const char * name, float w) :
		duck(name, w) {}
        void display(){
            std::cout << '\t' << _name << " is a decoyduck, weighted " << _weight << " KG\n";
        }
};
#endif 
