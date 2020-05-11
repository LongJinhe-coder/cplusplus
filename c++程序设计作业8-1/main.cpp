//main.cpp
#include"duck.h"
#include"mallardduck.h"
#include"redheadduck.h"
#include"flyable.h"
#include"quackable.h"
#include"rubberduck.h"
#include"decoyduck.h"
int main() {
	duck jack("Jack", 3);
	jack.display();
	// jack.quack();
	jack.swim();
	duck * peter = new duck("Peter", 2.5);
	peter->display();
	// peter->quack();
	peter->swim();
	mallardduck rose("Rose", 5);
	rose.display();
	rose.quack();
	rose.fly();
	rose.swim();
	redheadduck * amanda = new redheadduck("Amanda", 4);
	amanda->display();
	amanda->quack();
	amanda->fly();
	amanda->swim();
    rubberduck rubber("Rubber",1);
    rubber.display();
    rubber.quack();
    decoyduck * decoy = new decoyduck("Decoy",6);
    decoy->display();
	system("pause");
	return 0;
}

