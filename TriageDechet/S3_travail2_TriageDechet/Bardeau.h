#pragma once
#include "Dechet.h"
class Bardeau :
	public Dechet{
private:
	static int instanceBardeau;
public:
	Bardeau();
	Bardeau(Bardeau*);
	~Bardeau();

	static const int getNbInstance() {
		return Bardeau::instanceBardeau;
	}
};

