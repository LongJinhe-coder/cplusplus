#pragma once
#include"subject.h" 
#include"observer.h" 
#include"concreteState2.h" 
#include<iostream>
using std::cout;
class subject;
class concreteObserver2 :public observer {
public:
concreteObserver2(subject * s,const concreteState2 cs=NULL) :observer(s),_state(cs) { 
    // _state = -1;
}
virtual ~concreteObserver2() {}
void update(subject * s) {
if(_subject == s){ _state.setState2(s->getState()->getState2());
cout << "\t\t" << _state.getState2() << " is set locally\n";
}
}
private:
concreteState2 _state;
};