#include "Canette.h"

int Canette::instanceCanette = 0;

Canette::Canette() :
	Dechet(8, "Canette de Pepsi", 0, "Metallique", 3, 75, false, false) {

	Canette::instanceCanette++;
	std::cout << "Creation: Canette\n";
}

Canette::Canette(Canette* pseudoCanette) :Dechet(
	pseudoCanette->getPoids(), pseudoCanette->getDescription(), pseudoCanette->getTypePlastique(),
	pseudoCanette->getCouleur(), pseudoCanette->getMateriel(), pseudoCanette->getPurete(), pseudoCanette->estEnStyromousse(),
	pseudoCanette->estRigide()) {
	Canette::instanceCanette++;
	std::cout << "Creation: Canette\n";
}

Canette::~Canette(){
	Canette::instanceCanette--;
	std::cout << "Desctruction: Canette\n";
}
