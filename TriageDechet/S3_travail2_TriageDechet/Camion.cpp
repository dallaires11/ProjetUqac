#include "Camion.h"

int Camion::instanceCamion = 0;

Camion::Camion(int pseudoCapaciteMax) {
	capacite = 0;
	capaciteMax = pseudoCapaciteMax;
	instanceCamion++;
}

Camion::~Camion(){
	viderCamion();
	instanceCamion--;
}

bool Camion::ajouterDechet(DechetTraite* dechetTraite) {
	Dechet dechet = *dechetTraite->getDechet();
	if ((dechet.getPoids()) + capacite > capaciteMax)
		return false;
	else {
		pileDechet.push(dechetTraite);
		capacite += dechet.getPoids();
		return true;
	}
}

int Camion::viderCamion(){
	DechetTraite* curDechet;
	while (!pileDechet.empty()) {
		curDechet = pileDechet.top();
		pileDechet.pop();
		delete curDechet;
	}

	return capacite;
}