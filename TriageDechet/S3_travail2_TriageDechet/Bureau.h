#pragma once
#include "Dechet.h"
class Bureau :
	public Dechet{
private:
	static int instanceBureau;
public:
	Bureau();
	Bureau(Bureau*);
	~Bureau();

	static const int getNbInstance() {
		return Bureau::instanceBureau;
	}
};

