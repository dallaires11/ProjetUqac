#include "ChargementDechet.h"

int ChargementDechet::instanceChargeurDechet = 0;

ChargementDechet::ChargementDechet(Dechet* liste[50]) {
	current = 0;
	setDechets(liste);
	instanceChargeurDechet++;
}


ChargementDechet::~ChargementDechet() {
	destroyDechet();
	instanceChargeurDechet--;
}

Dechet* ChargementDechet::getDechet() {
	if (current < 41)
		return listeDechet[current++];
	else
		return NULL;
}

void ChargementDechet::destroyDechet() {
	for (int x = 0; x < 10; x++) {
		delete listeDechet[x];
	}

	return;
}

void ChargementDechet::setDechets(Dechet* liste[50]) {
	for (int x = 0; x < 50; x++) {
		listeDechet[x] = liste[x];
	}

	return;
}