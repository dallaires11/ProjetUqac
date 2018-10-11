#pragma once
#include "Dechet.h"
class PancarteElectorale :
	public Dechet{
private:
	static int instancePancarte;
public:
	PancarteElectorale();
	PancarteElectorale(PancarteElectorale*);
	~PancarteElectorale();

	static const int getNbInstance() {
		return PancarteElectorale::instancePancarte;
	}
};

