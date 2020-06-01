#pragma once
#include"subject.h" 
#include"concreteState3.h" 
#include<string>
using std::string;
class concreteSubject3 :public subject {
public:
concreteSubject3(const string & name,const concreteState3 s=NULL) :subject(name) {}
state* getState() const {
return _state;
}
void setState(state *s) { _state = s;
}
};