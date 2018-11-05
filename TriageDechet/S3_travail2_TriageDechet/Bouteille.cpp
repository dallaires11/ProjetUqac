#include "Bouteille.h"

int Bouteille::instanceBouteille = 0;

Bouteille::Bouteille() :
	Dechet(10, "Bouteille", 1, "Blanc", 1, 100, false, false) {

	Bouteille::instanceBouteille++;
	//std::cout << "Creation: Bouteille\n";
}

Bouteille::Bouteille(int type) :
	Dechet(10, "Bouteille", type, "Blanc", 1, 100, false, false) {

	Bouteille::instanceBouteille++;
	//std::cout << "Creation: Bouteille\n";
}

Bouteille::Bouteille(const Bouteille& pseudoBouteille) :Dechet(10, "Bouteille", 1, "Blanc", 1, 100, false, false) {
	Bouteille::instanceBouteille++;
	//std::cout << "Creation: Bouteille\n";
}

Bouteille::~Bouteille(){
	Bouteille::instanceBouteille--;
	//std::cout << "Desctruction: Bouteille\n";
}
