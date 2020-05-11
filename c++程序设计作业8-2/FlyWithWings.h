//FlyWithWings.h
#ifndef FLYWITHWINGS_H_
#define FLYWITHWINGS_H_
#include"FlyBehavior.h"
class FlyWithWings :public FlyBehavior{
public:
    virtual void fly(){
        std::cout << '\t' << "the duck can fly with wings\n";
    }
};
#endif 