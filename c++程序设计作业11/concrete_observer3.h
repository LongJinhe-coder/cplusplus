#pragma once
#include"subject.h" 
#include"observer.h" 
#include"concreteState3.h" 
#include<iostream>
using std::cout;
class subject;
class concreteObserver3 :public observer {
public:
concreteObserver3(subject * s,const concreteState3 cs=NULL) :observer(s),_state(cs) { 
    // _state = -1;
}
virtual ~concreteObserver3() {}
void update(subject * s) {
if(_subject == s){ _state.setState3(s->getState()->getState3());
cout << "\t\t" << _state.getState3() << " is set locally\n";
}
}
private:
concreteState3 _state;
};