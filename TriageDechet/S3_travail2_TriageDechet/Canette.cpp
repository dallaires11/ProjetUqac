#include "Canette.h"

int Canette::instanceCanette = 0;

Canette::Canette() :
	Dechet(8, "Canette de Pepsi", 0, "Metallique", 3, 75, false, false) {

	Canette::instanceCanette++;
	//std::cout << "Creation: Canette\n";
}

Canette::Canette(const Canette& pseudoCanette) :Dechet(8, "Canette de Pepsi", 0, "Metallique", 3, 75, false, false) {
	Canette::instanceCanette++;
	//std::cout << "Creation: Canette\n";
}

Canette::~Canette(){
	Canette::instanceCanette--;
	//std::cout << "Desctruction: Canette\n";
}
