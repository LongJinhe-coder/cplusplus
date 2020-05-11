//main.cpp
#include"duck.h"
#include"mallardduck.h"
#include"redheadduck.h"
#include"FlyBehavior.h"
#include"FlyWithWings.h"
#include"FlyNoWay.h"
#include"QuackBehavior.h"
#include"Quack.h"
#include"Squack.h"
#include"MuteQuack.h"
#include"rubberduck.h"
#include"decoyduck.h"
int main() {
	duck jack("Jack", 3);
	jack.display();
	// jack.setQuackBehavior(new FlyWithWings());
	// jack.performQuack();
	// jack.performFly();
	// jack.setQuackBehavior(new MuteQuack());
	// jack.performQuack();
	jack.swim();
	duck * peter = new duck("Peter", 2.5);
	peter->display();
	// peter->performQuack();
	// peter->performFly();
	peter->swim();
	mallardduck rose("Rose", 5);
	rose.display();
	rose.performQuack();
	rose.performFly();
	rose.setQuackBehavior(new MuteQuack());
	rose.performQuack();
	rose.swim();
	redheadduck * amanda = new redheadduck("Amanda", 4);
	amanda->display();
	amanda->performQuack();
	amanda->performFly();
	amanda->swim();
    rubberduck rubber("Rubber",1);
    rubber.display();
    rubber.performQuack();
	rubber.performFly();
	rubber.swim();
    decoyduck * decoy = new decoyduck("Decoy",6);
    decoy->display();
	decoy->performQuack();
	decoy->performFly();
	decoy->swim();
	system("pause");
	return 0;
}

