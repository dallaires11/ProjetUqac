#include "Camion.h"

int Camion::instanceCamion = 0;

Camion::Camion(int pseudoCapaciteMax) {
	capacite = 0;
	capaciteMax = pseudoCapaciteMax;
	instanceCamion++;
}

Camion::~Camion(){
	if (!pileDechet.empty())
		viderCamion();
	instanceCamion--;
}

bool Camion::ajouterDechet(DechetTraite* dechetTraite) {
	Dechet test = *(dechetTraite->getDechet());
	if ((test.getPoids()) + capacite > capaciteMax)
		return false;
	else {
		pileDechet.push(dechetTraite);
		return true;
	}
}

int Camion::viderCamion(){
	DechetTraite* curDechet;
	while (!pileDechet.empty()) {
		curDechet = pileDechet.top();
		delete curDechet;
		pileDechet.pop();
	}

	return capacite;
}