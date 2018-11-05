#pragma once
#include "Dechet.h"
class Bureau :
	public Dechet{
private:
	static int instanceBureau;
public:
	Bureau();
	Bureau(const Bureau&);
	~Bureau();

	static const int getNbInstance() {
		return Bureau::instanceBureau;
	}
};

