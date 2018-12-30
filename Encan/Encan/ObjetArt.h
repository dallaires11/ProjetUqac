#pragma once
#include "Objet.h"
class ObjetArt :
	public Objet{
private:
	static int instanceObjetArt;

	int renomme, valeur, dimension;
	std::string description,type;

	void setRenomme(int);
public:
	ObjetArt(int,int,int,std::string);
	~ObjetArt();

	std::string getInfo();

	int getValeur() {
		return valeur;
	}

	static const int getNbInstance() {
		return ObjetArt::instanceObjetArt;
	}
};

