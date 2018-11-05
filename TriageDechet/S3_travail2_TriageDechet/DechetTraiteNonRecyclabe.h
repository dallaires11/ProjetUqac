#pragma once
#include "DechetTraite.h"
class DechetTraiteNonRecyclabe :
	public DechetTraite{
private:
	static int instanceDechetTraiteNR;
public:
	DechetTraiteNonRecyclabe(Dechet*);
	DechetTraiteNonRecyclabe(const DechetTraiteNonRecyclabe&);
	~DechetTraiteNonRecyclabe();

	static const int getNbInstance() {
		return DechetTraiteNonRecyclabe::instanceDechetTraiteNR;
	}
};

