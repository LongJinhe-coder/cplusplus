//main.cpp

#include"duck.h"
#include"mallardduck.h"
#include"redheadduck.h"
#include"rubberduck.h"
#include"decoyduck.h"
#include"robotduck.h"
#include"flywithwings.h"
#include"flynoway.h"
#include"quack.h"
#include"squeak.h"
#include"mutequack.h"
#include"walkwithroll.h"
#include"walk.h"
#include"walknoway.h"
#include<iostream>
int main() {
	//more cases
	Duck * ducks[6];
	ducks[0] = new Duck();
	ducks[1] = new MallardDuck(new Quack(), new FlyWithWings());
	ducks[2] = new RedheadDuck(new Quack(), new FlyWithWings());
	ducks[3] = new RubberDuck(new Squeak());
	ducks[4] = new DecoyDuck();
	ducks[5] = new RobotDuck(new Quack(), new FlyWithWings(), new WalkWithRoll());

	for (int i = 0; i < 6; ++i) {
		ducks[i]->display();
		ducks[i]->swim();
		ducks[i]->fly();
		ducks[i]->quack();
		ducks[i]->walk();
		std::cout << std::endl;
	}

	for (int i = 0; i < 6; ++i)
		delete ducks[i];
}