#pragma once
#include "Dechet.h"
class ReveEleve :
	public Dechet{
private:
	static int instanceReve;
public:
	ReveEleve();
	ReveEleve(ReveEleve*);
	~ReveEleve();

	static const int getNbInstance() {
		return ReveEleve::instanceReve;
	}
};

