#include "Bardeau.h"

int Bardeau::instanceBardeau = 0;

Bardeau::Bardeau() :
	Dechet(45, "Reste de toiture", 0, "Noir", 9, 35, false, true) {

	Bardeau::instanceBardeau++;
	//std::cout << "Creation: Bardeau\n";
}

Bardeau::Bardeau(Bardeau* pseudoBardeau) :Dechet(
	pseudoBardeau->getPoids(), pseudoBardeau->getDescription(), pseudoBardeau->getTypePlastique(),
	pseudoBardeau->getCouleur(), pseudoBardeau->getMateriel(), pseudoBardeau->getPurete(), pseudoBardeau->estEnStyromousse(),
	pseudoBardeau->estRigide()) {
	Bardeau::instanceBardeau++;
	//std::cout << "Creation: Bardeau\n";
}

Bardeau::~Bardeau(){
	Bardeau::instanceBardeau--;
	//std::cout << "Desctruction: Bardeau\n";
}
