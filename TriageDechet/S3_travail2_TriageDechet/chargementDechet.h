#pragma once
#include"Dechet.h"
class chargementDechet{
private:
	static int instanceChargeurDechet;
	int current;
	Dechet* listeDechet[50];
	void setDechets(Dechet*[50]);
	void destroyDechet();
public:
	chargementDechet(Dechet*[50]);

	Dechet* getDechet();
	~chargementDechet();

	static const int getNbInstance() {
		return chargementDechet::instanceChargeurDechet;
	}
};

