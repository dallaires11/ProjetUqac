#pragma once
#include "Objet.h"
class ObjetService :
	public Objet{
private:
	static int instanceObjetService;

	int tarifBase, experience,fraisBase;
	std::string serviceDesc;

public:
	ObjetService(int,int,int,std::string);
	~ObjetService();

	std::string getInfo();

	int getValeur() {
		return fraisBase;
	}

	static const int getNbInstance() {
		return ObjetService::instanceObjetService;
	}
};

