#include "ChargementDechet.h"

int ChargementDechet::instanceChargeurDechet = 0;

ChargementDechet::ChargementDechet(std::list<Dechet*>* liste) {
	setDechets(liste);
	instanceChargeurDechet++;
}

ChargementDechet::ChargementDechet(const ChargementDechet& pseudoChargement) {
	listeDechet = pseudoChargement.listeDechet;
	instanceChargeurDechet++;
}


ChargementDechet::~ChargementDechet() {
	instanceChargeurDechet--;
}

Dechet* ChargementDechet::getDechet() {
	if (listeDechet->size() != 0) {
		Dechet* dechet = listeDechet->front();
		listeDechet->pop_front();
		return dechet;
	}else
		return NULL;
}

void ChargementDechet::setDechets(std::list<Dechet*>* liste) {
	listeDechet = liste;

	return;
}