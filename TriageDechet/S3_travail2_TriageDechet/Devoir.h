#pragma once
#include "Dechet.h"
class Devoir :
	public Dechet{
private:
	static int instanceDevoir;
public:
	Devoir();
	Devoir(Devoir*);
	~Devoir();

	static const int getNbInstance() {
		return Devoir::instanceDevoir;
	}
};

