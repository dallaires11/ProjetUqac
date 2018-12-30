#include "ObjetAntique.h"

int ObjetAntique::instanceObjetAntique = 0;

ObjetAntique::ObjetAntique(int PrixDepart,std::string etat, std::string periode, std::string description):Objet(PrixDepart){
	this->description = description;
	valeur = PrixDepart;
	this->etat = etat;
	this->periode = periode;
	ObjetAntique::instanceObjetAntique++;
}

ObjetAntique::~ObjetAntique(){
	ObjetAntique::instanceObjetAntique--;
}

std::string ObjetAntique::getInfo() {
	return description;
}
