#pragma once
#include "DechetTraite.h"
class DechetTraiteRecyclabe :
	public DechetTraite{
private:
	static int instanceDechetTraiteR;
public:
	DechetTraiteRecyclabe(Dechet*);
	DechetTraiteRecyclabe(const DechetTraiteRecyclabe&);
	~DechetTraiteRecyclabe();

	static const int getNbInstance() {
		return DechetTraiteRecyclabe::instanceDechetTraiteR;
	}
};

