#pragma once
#include"subject.h" 
#include"concreteState2.h"
#include<string>
using std::string;
class concreteSubject2 :public subject {
public:
concreteSubject2(const string & name,const concreteState2 s=NULL) :subject(name) {}
state* getState() const {
return _state;
}
void setState(state *s) { _state = s;
}
};