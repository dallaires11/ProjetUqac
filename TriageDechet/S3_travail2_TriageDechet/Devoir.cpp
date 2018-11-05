#include "Devoir.h"

int Devoir::instanceDevoir = 0;

Devoir::Devoir():
	Dechet(2,"Pile de devoir",0,"Blanc",7,75,false,false){

	Devoir::instanceDevoir++;
	//std::cout << "Creation: Devoir\n";
}

Devoir::Devoir(const Devoir& pseudoDevoir):Dechet(2, "Pile de devoir", 0, "Blanc", 7, 75, false, false) {
	Devoir::instanceDevoir++;
	//std::cout << "Creation: Devoir\n";
}


Devoir::~Devoir(){
	Devoir::instanceDevoir--;
	//std::cout << "Desctruction: Devoir\n";
}