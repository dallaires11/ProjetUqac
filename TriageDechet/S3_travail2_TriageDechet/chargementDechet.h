#pragma once
#include"Dechet.h"
class ChargementDechet {
private:
	static int instanceChargeurDechet;
	int current;
	Dechet* listeDechet[50];
	void setDechets(Dechet*[50]);
	void destroyDechet();
public:
	ChargementDechet(Dechet*[50]);

	Dechet* getDechet();
	~ChargementDechet();

	static const int getNbInstance() {
		return ChargementDechet::instanceChargeurDechet;
	}
};