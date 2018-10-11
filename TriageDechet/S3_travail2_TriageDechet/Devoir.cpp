#include "Devoir.h"

int Devoir::instanceDevoir = 0;

Devoir::Devoir():
	Dechet(2,"Pile de devoir",0,"Blanc",7,75,false,false){

	Devoir::instanceDevoir++;
	std::cout << "Creation: Devoir\n";
}

Devoir::Devoir(Devoir* pseudoDevoir):Dechet(
	pseudoDevoir->getPoids(),pseudoDevoir->getDescription(),pseudoDevoir->getTypePlastique(),
	pseudoDevoir->getCouleur(),pseudoDevoir->getMateriel(),pseudoDevoir->getPurete(),pseudoDevoir->estEnStyromousse(),
	pseudoDevoir->estRigide()){
	Devoir::instanceDevoir++;
	std::cout << "Creation: Devoir\n";
}


Devoir::~Devoir(){
	Devoir::instanceDevoir--;
	std::cout << "Desctruction: Devoir\n";
}