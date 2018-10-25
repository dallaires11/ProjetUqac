#include "Ustensile.h"

int Ustensile::instanceUstensile = 0;

Ustensile::Ustensile() :
	Dechet(1, "Couteau,fourchette", 5, "Blanc", 2, 75, false, false) {

	Ustensile::instanceUstensile++;
	//std::cout << "Creation: Ustensile\n";
}

Ustensile::Ustensile(Ustensile* pseudoUstensile) :Dechet(
	pseudoUstensile->getPoids(), pseudoUstensile->getDescription(), pseudoUstensile->getTypePlastique(),
	pseudoUstensile->getCouleur(), pseudoUstensile->getMateriel(), pseudoUstensile->getPurete(), pseudoUstensile->estEnStyromousse(),
	pseudoUstensile->estRigide()) {
	Ustensile::instanceUstensile++;
	//std::cout << "Creation: Ustensile\n";

}

Ustensile::~Ustensile(){
	Ustensile::instanceUstensile--;
	//std::cout << "Desctruction: Ustensile\n";
}
