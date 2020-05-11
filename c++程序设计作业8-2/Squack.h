//Squack.h
#ifndef SQUACK_H_
#define SQUACK_H_
#include"QuackBehavior.h"
class Squack :public QuackBehavior{
public:
    virtual void quack(){
        std::cout << '\t' << "the duck can zhi zhi giao\n";
    }
};
#endif 