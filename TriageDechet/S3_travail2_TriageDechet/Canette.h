#pragma once
#include "Dechet.h"
class Canette :
	public Dechet{
private:
	static int instanceCanette;
public:
	Canette();
	Canette(Canette*);
	~Canette();

	static const int getNbInstance() {
		return Canette::instanceCanette;
	}
};

