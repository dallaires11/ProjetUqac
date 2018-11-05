#pragma once
#include"Dechet.h"
#include<list>
class ChargementDechet {
private:
	static int instanceChargeurDechet;
	std::list<Dechet*>* listeDechet;
	void setDechets(std::list<Dechet*>*);
public:
	ChargementDechet(std::list<Dechet*>*);
	ChargementDechet(const ChargementDechet&);

	Dechet* getDechet();
	~ChargementDechet();

	static const int getNbInstance() {
		return ChargementDechet::instanceChargeurDechet;
	}
};