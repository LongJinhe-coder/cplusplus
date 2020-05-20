//duck.cpp
#include"duck.h"
#include<iostream>
void Duck::display() {
	std::cout << "\tDuck is handsome\n";
}

void Duck::swim() {
	std::cout << "\tDuck is swimming\n";
}

void Duck::fly() {
	if (_fb)
		_fb->fly();
}

void Duck::quack() {
	if (_qb)
		_qb->quack();
}

void Duck::walk() {
	if (_wb)
		_wb->walk();
}
