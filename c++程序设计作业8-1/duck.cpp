//duck.cpp
#include"duck.h"
#include<iostream>
// void duck::quack() {
// 	std::cout << '\t' << _name << " is quacking\n";
// }
void duck::display() {
	std::cout << '\t' << _name << "\'s weight is " << _weight << "KG\n";
}
void duck::swim() {
	std::cout << '\t' << _name << " is swimming\n";
}
