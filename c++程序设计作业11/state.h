//state.h
#ifndef STATE_H_
#define STATE_H_
#include <iostream>
class state {
public:
	virtual ~state() {}
    virtual void setState1(int s){};
    virtual int getState1(){};
    virtual void setState2(char* s){};
    virtual char* getState2(){};
    virtual void setState3(bool s){};
    virtual bool getState3(){};

};
#endif 