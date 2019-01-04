#pragma once
#include"EtatLibre.h"
#include"EtatVendu.h"
#include <string>
class Objet{
private:
	static int instanceObjet;

	int prixDepart,prixVenteMin,enchereMin,enchereMax;

	EtatObjet* etat;

public:
	Objet(int);
	virtual ~Objet();

	virtual std::string getInfo() = 0;

	virtual int getValeur() = 0;

	static const int getNbInstance() {
		return Objet::instanceObjet;
	}
};

