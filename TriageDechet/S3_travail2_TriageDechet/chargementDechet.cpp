#include "chargementDechet.h"

int chargementDechet::instanceChargeurDechet = 0;

chargementDechet::chargementDechet(Dechet* liste[50]){
	current = 0;
	setDechets(liste);
	instanceChargeurDechet++;
}


chargementDechet::~chargementDechet(){
	destroyDechet();
	instanceChargeurDechet--;
}

Dechet* chargementDechet::getDechet() {
	if (current < 41)
		return listeDechet[current++];
	else
		return NULL;
}

void chargementDechet::destroyDechet() {
	for (int x = 0; x < 10; x++) {
		delete listeDechet[x];
	}

	return;
}

void chargementDechet::setDechets(Dechet* liste[50]) {
	for (int x = 0; x < 50; x++) {
		listeDechet[x] = liste[x];
	}

	return;


}