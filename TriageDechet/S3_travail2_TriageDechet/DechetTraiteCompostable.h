#pragma once
#include "DechetTraite.h"
class DechetTraiteCompostable :
	public DechetTraite{
private:
	static int instanceDechetTraiteC;
public:
	DechetTraiteCompostable(Dechet*);
	~DechetTraiteCompostable();

	static const int getNbInstance() {
		return DechetTraiteCompostable::instanceDechetTraiteC;
	}
};

