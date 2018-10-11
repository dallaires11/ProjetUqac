#pragma once
#include "Dechet.h"
class Plante :
	public Dechet{
private:
	static int instancePlante;
public:
	Plante();
	Plante(std::string);
	Plante(Plante*);
	~Plante();

	static const int getNbInstance() {
		return Plante::instancePlante;
	}
};