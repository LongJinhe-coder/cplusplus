#pragma once
#include"subject.h" 
#include"observer.h" 
#include"concreteState1.h" 
#include<iostream>
using std::cout;
class subject;
class concreteObserver1 :public observer {
public:
concreteObserver1(subject * s,const concreteState1 cs=NULL) :observer(s),_state(cs) { 
    // _state = -1;
}
virtual ~concreteObserver1() {}
void update(subject * s) {
if(_subject == s){ _state.setState1(s->getState()->getState1());
cout << "\t\t" << _state.getState1() << " is set locally\n";
}
}
private:
concreteState1 _state;
};