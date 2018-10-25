#include "Plante.h"

int Plante::instancePlante = 0;

Plante::Plante() :
	Dechet(100, "Experience de laboratoire", 0, "vert", 4, 100, false, true) {

	Plante::instancePlante++;
	//std::cout << "Creation: Plante\n";
}

Plante::Plante(std::string iCouleur) :
	Dechet(42, "Jolie plante", 0, iCouleur, 4, 100, false, false) {

	Plante::instancePlante++;
	//std::cout << "Creation: Plante\n";
}

Plante::Plante(Plante* pseudoPlante) :Dechet(
	pseudoPlante->getPoids(), pseudoPlante->getDescription(), pseudoPlante->getTypePlastique(),
	pseudoPlante->getCouleur(), pseudoPlante->getMateriel(), pseudoPlante->getPurete(), pseudoPlante->estEnStyromousse(),
	pseudoPlante->estRigide()) {
	Plante::instancePlante++;
	//std::cout << "Creation: Plante\n";
}

Plante::~Plante(){
	Plante::instancePlante--;
	//std::cout << "Desctruction: Plante\n";
}