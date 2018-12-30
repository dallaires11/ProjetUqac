#pragma once
#include"ObjetFactory.h"
#include"SalleAttente.h"

class VendeurFactory{
private:
	static int instanceVendeurFac;

	SalleAttente* salleAttente;

	std::string prenom[10];
	std::string nom[10];
	std::thread comportement;
	bool running;
	ObjetFactory* objFactory;

	std::string getNom();
	std::string getPrenom();
	int getTypeVente();
	void ajouterVendeur();
	void run();

public:
	VendeurFactory(SalleAttente*);
	~VendeurFactory();

	void start();
	void stop();

	static int getNbIntance() {
		return VendeurFactory::instanceVendeurFac;
	}
};