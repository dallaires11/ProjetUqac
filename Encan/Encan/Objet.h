#pragma once
//#include<queue>
#include <string>
class Objet{
private:
	static int instanceObjet;

	int prixDepart,prixVenteMin,enchereMin,enchereMax;

public:
	Objet(int);
	~Objet();

	virtual std::string getInfo() = 0;

	static const int getNbInstance() {
		return Objet::instanceObjet;
	}
};

