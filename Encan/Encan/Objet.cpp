#include "Objet.h"

int Objet::instanceObjet = 0;

Objet::Objet(int prixDepart){
	this->prixDepart = prixDepart;
	Objet::instanceObjet++;
}

Objet::~Objet(){
	Objet::instanceObjet--;
}
