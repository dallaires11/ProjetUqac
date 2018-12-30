#pragma once
#include "Objet.h"
class ObjetAntique :
	public Objet{
private:
	static int instanceObjetAntique;
	std::string description,periode,etat;
	int valeur;
public:
	ObjetAntique(int,std::string,std::string,std::string);
	~ObjetAntique();

	std::string getInfo();

	int getValeur() {
		return valeur;
	}

	static const int getNbInstance() {
		return ObjetAntique::instanceObjetAntique;
	}
};

