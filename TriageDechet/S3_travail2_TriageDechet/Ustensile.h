#pragma once
#include "Dechet.h"
class Ustensile :
	public Dechet{
private:
	static int instanceUstensile;
public:
	Ustensile();
	Ustensile(Ustensile*);
	~Ustensile();

	static const int getNbInstance() {
		return Ustensile::instanceUstensile;
	}
};

