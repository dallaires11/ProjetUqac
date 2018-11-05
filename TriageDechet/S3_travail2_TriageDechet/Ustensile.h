#pragma once
#include "Dechet.h"
class Ustensile :
	public Dechet{
private:
	static int instanceUstensile;
public:
	Ustensile();
	Ustensile(const Ustensile&);
	~Ustensile();

	static const int getNbInstance() {
		return Ustensile::instanceUstensile;
	}
};

