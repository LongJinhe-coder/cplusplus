//quackable.h
#ifndef QUACKABLE_H_
#define QUACKABLE_H_
#include<string>
#include<iostream>
class quackable {
public:
    void quack(){
        std::cout << '\t'<<"duck is quacking"<<std::endl;
    };
};
#endif 
