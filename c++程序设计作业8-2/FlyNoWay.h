//FlyNoWay.h
#ifndef FLYNOWAY_H_
#define FLYNOWAY_H_
#include"FlyBehavior.h"
class FlyNoWay :public FlyBehavior{
public:
    virtual void fly(){
        std::cout << '\t' << "the duck can not fly\n";
    }
};
#endif 