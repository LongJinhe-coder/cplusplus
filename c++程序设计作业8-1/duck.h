//duck.h
#ifndef DUCK_H_
#define DUCK_H_
#include<string>
#include<iostream>
class duck {
protected:
	float _weight;
	std::string _name;
public:
	duck(const char * name, float w) :
		_name(name), _weight(w) {
		std::cout << "Duck " << name << " is born\n";
	}
	void display();
	// void quack();
	void swim();
};
#endif 
