#include "ChargementDechet.h"

int ChargementDechet::instanceChargeurDechet = 0;

ChargementDechet::ChargementDechet(std::list<Dechet*>* liste) {
	setDechets(liste);
	instanceChargeurDechet++;
}


ChargementDechet::~ChargementDechet() {
	destroyDechet();
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

void ChargementDechet::destroyDechet() {
	Dechet* dechet = nullptr;
	while (!listeDechet->empty())
	{
		dechet = listeDechet->front();
		listeDechet->pop_front();
		delete dechet;
	}
	delete listeDechet;

	return;
}

void ChargementDechet::setDechets(std::list<Dechet*>* liste) {
	listeDechet = liste;

	return;
}