//Quack.h
#ifndef QUACK_H_
#define QUACK_H_
#include"QuackBehavior.h"
class Quack :public QuackBehavior{
public:
    virtual void quack(){
        std::cout << '\t' << "the duck can giao\n";
    }
};
#endif 