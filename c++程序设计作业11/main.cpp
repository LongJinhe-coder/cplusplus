#include"concrete_observer1.h" 
#include"concrete_subject1.h" 
#include"concreteState1.h" 
#include"concrete_observer2.h" 
#include"concrete_subject2.h" 
#include"concreteState2.h" 
#include"concrete_observer3.h" 
#include"concrete_subject3.h" 
#include"concreteState3.h" 
#include"state.h" 
#include"subject.h" 
#include"observer.h" 
#include<iostream>
using std::cout;
int main() {
cout << "1 subject1 and 3 observers1 are created\n";
subject * sub1 = new concreteSubject1("HQU Zone-1");
observer * ob1 = new concreteObserver1(sub1);
observer * ob2 = new concreteObserver1(sub1);
observer * ob3 = new concreteObserver1(sub1);
cout << "3 observers are attached to subject\n";
sub1->attach(ob1);
sub1->attach(ob2);
sub1->attach(ob3);
state * state1 = new concreteState1(999);
cout << "State " << state1->getState1() << " is set on subject1\n";
sub1->setState(state1);
cout << "New state " << state1->getState1() << " is ready for broadcasting\n";
sub1->notify();
cout << "3 observers1 are detached from the subject1\n";
sub1->detach(ob1);
sub1->detach(ob2);
sub1->detach(ob3);
cout << "Destroying 3 observers1 and 1 subject1\n";
delete ob3;
delete ob2;
delete ob1;
delete sub1;
cout << "1 subject2 and 3 observers2 are created\n";
subject * sub2 = new concreteSubject2("HQU Zone-2");
observer * ob4 = new concreteObserver2(sub1);
observer * ob5 = new concreteObserver2(sub1);
observer * ob6 = new concreteObserver2(sub1);
cout << "3 observers2 are attached to subject2\n";
sub2->attach(ob4);
sub2->attach(ob5);
sub2->attach(ob6);
state * state2 = new concreteState2("hello");
cout << "State " << state2->getState2() << " is set on subjec2\n";
sub2->setState(state2);
cout << "New state " << state2->getState2() << " is ready for broadcasting\n";
sub2->notify();
cout << "3 observers2 are detached from the subject2\n";
sub2->detach(ob1);
sub2->detach(ob2);
sub2->detach(ob3);
cout << "Destroying 3 observers2 and 1 subject2\n";
delete ob4;
delete ob5;
delete ob6;
delete sub2;
cout << "1 subject3 and 3 observers3 are created\n";
subject * sub3 = new concreteSubject3("HQU Zone-3");
observer * ob7 = new concreteObserver3(sub3);
observer * ob8 = new concreteObserver3(sub3);
observer * ob9 = new concreteObserver3(sub3);
cout << "3 observers3 are attached to subject3\n";
sub3->attach(ob7);
sub3->attach(ob8);
sub3->attach(ob9);
state * state3 = new concreteState3(true);
cout << "State " << state3->getState3() << " is set on subjec3\n";
sub3->setState(state3);
cout << "New state " << state3->getState3() << " is ready for broadcasting\n";
sub3->notify();
cout << "3 observers3 are detached from the subject3\n";
sub3->detach(ob7);
sub3->detach(ob8);
sub3->detach(ob9);
cout << "Destroying 3 observers3 and 1 subject3\n";
delete ob7;
delete ob8;
delete ob9;
delete sub3;
return 0;
}