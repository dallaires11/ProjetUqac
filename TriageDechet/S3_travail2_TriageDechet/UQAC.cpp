#include "UQAC.h"
#include <list>

int UQAC::instanceUqac = 0;

UQAC::UQAC(){
	instanceUqac++;
}

UQAC::UQAC(const UQAC& pseudoUqac) {
	instanceUqac++;
}


UQAC::~UQAC(){
	instanceUqac--;
}

ChargementDechet* UQAC::getChargementDechets() {
	std::list<Dechet*>* listeDechet = new std::list<Dechet*>;

	listeDechet->push_back( new PancarteElectorale());
	listeDechet->push_back(new Bouteille());
	listeDechet->push_back(new Ustensile());
	listeDechet->push_back(new Canette());
	listeDechet->push_back(new Plante());
	listeDechet->push_back(new Bureau());
	listeDechet->push_back(new Bouffe());
	listeDechet->push_back(new Devoir());
	listeDechet->push_back(new AssietteJetable());
	listeDechet->push_back(new Bardeau());
	listeDechet->push_back(new PancarteElectorale());
	listeDechet->push_back(new Bouteille());
	listeDechet->push_back(new Ustensile());
	listeDechet->push_back(new Canette());
	listeDechet->push_back(new Plante());
	listeDechet->push_back(new Bureau());
	listeDechet->push_back(new Bouffe());
	listeDechet->push_back(new Devoir());
	listeDechet->push_back(new AssietteJetable());
	listeDechet->push_back(new Bardeau());
	listeDechet->push_back(new PancarteElectorale());
	listeDechet->push_back(new Bouteille());
	listeDechet->push_back(new Ustensile());
	listeDechet->push_back(new Canette());
	listeDechet->push_back(new Plante());
	listeDechet->push_back(new Bureau());
	listeDechet->push_back(new Bouffe());
	listeDechet->push_back(new Devoir());
	listeDechet->push_back(new AssietteJetable());
	listeDechet->push_back(new Bardeau());
	listeDechet->push_back(new PancarteElectorale());
	listeDechet->push_back(new Bouteille());
	listeDechet->push_back(new Ustensile());
	listeDechet->push_back(new Canette());
	listeDechet->push_back(new Plante());
	listeDechet->push_back(new Bureau());
	listeDechet->push_back(new Bouffe());
	listeDechet->push_back(new Devoir());
	listeDechet->push_back(new AssietteJetable());
	listeDechet->push_back(new Bardeau());
	listeDechet->push_back(new PancarteElectorale());
	listeDechet->push_back(new Bouteille());
	listeDechet->push_back(new Ustensile());
	listeDechet->push_back(new Canette());
	listeDechet->push_back(new Plante());
	listeDechet->push_back(new Bureau());
	listeDechet->push_back(new Bouffe());
	listeDechet->push_back(new Devoir());
	listeDechet->push_back(new AssietteJetable());
	listeDechet->push_back(new ReveEleve());
	return new ChargementDechet(listeDechet);
}