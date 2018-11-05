#include "Ustensile.h"

int Ustensile::instanceUstensile = 0;

Ustensile::Ustensile() :
	Dechet(1, "Couteau,fourchette", 5, "Blanc", 2, 75, false, false) {

	Ustensile::instanceUstensile++;
	//std::cout << "Creation: Ustensile\n";
}

Ustensile::Ustensile(const Ustensile& pseudoUstensile) :
	Dechet(1, "Couteau,fourchette", 5, "Blanc", 2, 75, false, false) {
	Ustensile::instanceUstensile++;
	//std::cout << "Creation: Ustensile\n";

}

Ustensile::~Ustensile(){
	Ustensile::instanceUstensile--;
	//std::cout << "Desctruction: Ustensile\n";
}
