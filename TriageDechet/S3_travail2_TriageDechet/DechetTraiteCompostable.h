#pragma once
#include "DechetTraite.h"
class DechetTraiteCompostable :
	public DechetTraite{
private:
	static int instanceDechetTraiteC;
public:
	DechetTraiteCompostable(Dechet*);
	DechetTraiteCompostable(const DechetTraiteCompostable&);
	~DechetTraiteCompostable();

	static const int getNbInstance() {
		return DechetTraiteCompostable::instanceDechetTraiteC;
	}
};

