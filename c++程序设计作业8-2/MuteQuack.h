//MuteQuack.h
#ifndef MUTEQUACK_H_
#define MUTEQUACK_H_
#include"QuackBehavior.h"
class MuteQuack :public QuackBehavior{
public:
    virtual void quack(){
        std::cout << '\t' << "the duck can not giao\n";
    }
};
#endif 