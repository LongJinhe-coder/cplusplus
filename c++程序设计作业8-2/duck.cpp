//duck.cpp
#include"duck.h"
#include<iostream>
void duck::display() {
	std::cout << '\t' << _name << "\'s weight is " << _weight << "KG\n";
}
void duck::swim() {
	std::cout << '\t' << _name << " is swimming\n";
}
