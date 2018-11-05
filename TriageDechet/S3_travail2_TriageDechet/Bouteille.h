#pragma once
#include "Dechet.h"
class Bouteille :
	public Dechet{
private:
	static int instanceBouteille;
public:
	Bouteille();
	Bouteille(int);
	Bouteille(const Bouteille&);
	~Bouteille();

	static const int getNbInstance() {
		return Bouteille::instanceBouteille;
	}
};

