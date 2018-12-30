#pragma once
#include"SalleAttente.h"
//type 1 old 2 art 3 service
class AcheteurFactory{
private:
	static int instanceAcheteurFac;
	std::string nom[10];
	std::string prenom[10];
	std::thread comportement;
	SalleAttente* salleAttente;
	void setNom();
	std::string getPrenom();
	std::string getNom();
	
	int getMillieuSocial();
	int getBudget(int);
	int getNbBid(int);
	int getTypeProduit();
	int getBidIncrement(int);
	void ajouterAcheteur();
	bool running;
	void run();
public:
	AcheteurFactory(SalleAttente*);
	~AcheteurFactory();

	void start();
	void stop();

	static int getNbIntance() {
		return AcheteurFactory::instanceAcheteurFac;
	}
};