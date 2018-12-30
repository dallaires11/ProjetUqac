#pragma once
#include"Encan.h"
#include"SalleAttente.h"

class Bouncer{
private:
	static int instanceBouncer;

	SalleAttente* salleAtt;
	std::thread comportement;
	bool running;

	void addNewArtVendeur(Vendeur*);
	void addNewAntiqueVendeur(Vendeur*);
	void addNewServiceVendeur(Vendeur*);

	void addNewArtAcheteur(Acheteur*);
	void addNewAntiqueAcheteur(Acheteur*);
	void addNewServiceAcheteur(Acheteur*);

	void run();
public:
	Bouncer(SalleAttente*);
	~Bouncer();

	void inviterVendeur();
	void inviterAcheteur();

	void start();
	void stop();

	static int getNbIntance() {
		return Bouncer::instanceBouncer;
	}
};