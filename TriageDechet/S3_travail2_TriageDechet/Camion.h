#pragma once
#include <stack>
#include"DechetTraite.h"
class Camion{
private:
	static int instanceCamion;
	int capaciteMax;
	int capacite;
	std::stack <DechetTraite*> pileDechet;
public:
	Camion(int);
	Camion(const Camion&);
	virtual ~Camion();

	bool ajouterDechet(DechetTraite*);

	int viderCamion();

	static const int getNbInstance() {
		return Camion::instanceCamion;
	}
};