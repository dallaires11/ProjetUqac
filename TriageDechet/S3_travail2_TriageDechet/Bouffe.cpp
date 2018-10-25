#include "Bouffe.h"

int Bouffe::instanceBouffe = 0;

Bouffe::Bouffe() :
	Dechet(17, "Reste de la cafeteria", 0, "Brun", 6, 10, false, false) {

	Bouffe::instanceBouffe++;
	//std::cout << "Creation: Bouffe\n";
}

Bouffe::Bouffe(Bouffe* pseudoBouffe) :Dechet(
	pseudoBouffe->getPoids(), pseudoBouffe->getDescription(), pseudoBouffe->getTypePlastique(),
	pseudoBouffe->getCouleur(), pseudoBouffe->getMateriel(), pseudoBouffe->getPurete(), pseudoBouffe->estEnStyromousse(),
	pseudoBouffe->estRigide()) {
	Bouffe::instanceBouffe++;
	//std::cout << "Creation: Bouffe\n";
}

Bouffe::~Bouffe(){
	Bouffe::instanceBouffe--;
	//std::cout << "Desctruction: Bouffe\n";
}
