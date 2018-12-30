#include "ObjetArt.h"

int ObjetArt::instanceObjetArt = 0;

ObjetArt::ObjetArt(int prixDepart,int renomme,int dimension,std::string description):Objet(prixDepart){
	setRenomme(renomme);
	this->valeur = prixDepart;
	this->dimension = dimension;
	this->description = description;
	ObjetArt::instanceObjetArt++;
}

ObjetArt::~ObjetArt(){
	ObjetArt::instanceObjetArt--;
}

void ObjetArt::setRenomme(int renomme) {
	if (renomme > 100)
		this->renomme = 100;
	else if (renomme <= 0)
		this->renomme = 1;
	else
		this->renomme = renomme;
}

std::string ObjetArt::getInfo() {
	return description;
}