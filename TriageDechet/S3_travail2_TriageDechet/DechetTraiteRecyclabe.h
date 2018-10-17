#pragma once
#include "DechetTraite.h"
class DechetTraiteRecyclabe :
	public DechetTraite{
private:
	static int instanceDechetTraiteR;
public:
	DechetTraiteRecyclabe(Dechet*);
	~DechetTraiteRecyclabe();

	static const int getNbInstance() {
		return DechetTraiteRecyclabe::instanceDechetTraiteR;
	}
};

