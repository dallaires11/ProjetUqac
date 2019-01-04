#include "Objet.h"

int Objet::instanceObjet = 0;

Objet::Objet(int prixDepart){
	this->prixDepart = prixDepart;
	etat = new EtatLibre();
	Objet::instanceObjet++;
}

Objet::~Objet(){
	delete etat;
	etat = new EtatVendu();
	delete etat;
	Objet::instanceObjet--;
}
