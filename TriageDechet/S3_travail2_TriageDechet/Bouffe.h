#pragma once
#include "Dechet.h"
class Bouffe :
	public Dechet{
private:
	static int instanceBouffe;
public:
	Bouffe();
	Bouffe(Bouffe*);
	~Bouffe();

	static const int getNbInstance() {
		return Bouffe::instanceBouffe;
	}
};

