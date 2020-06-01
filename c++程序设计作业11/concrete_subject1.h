#pragma once
#include"subject.h" 
#include<string>
using std::string;
class concreteSubject1 :public subject {
public:
concreteSubject1(const string & name,const concreteState1 s=NULL) :subject(name) {}
state* getState() const {
return _state;
}
void setState(state *s) { _state = s;
}
};