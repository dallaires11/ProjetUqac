#pragma once
#include "DechetTraite.h"
class DechetTraiteNonRecyclabe :
	public DechetTraite{
private:
	static int instanceDechetTraiteNR;
public:
	DechetTraiteNonRecyclabe(Dechet*);
	~DechetTraiteNonRecyclabe();

	static const int getNbInstance() {
		return DechetTraiteNonRecyclabe::instanceDechetTraiteNR;
	}
};

