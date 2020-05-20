//mutequack.h
#ifndef MUTEQUACK_H_
#define MUTEQUACK_H_
#include"quackbehavior.h"
class MuteQuack :public QuackBehavior {
public:
	void quack() {
		//nothing to do, just be silent
	}
};
#endif 