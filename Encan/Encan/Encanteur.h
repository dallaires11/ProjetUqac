#pragma once
#include"Vendeur.h"
#include"Logger.h"
#include"ObjetAntique.h"
#include"ObjetArt.h"
#include"ObjetService.h"
#include<mutex>
#include<vector>
class Encanteur{
private:
	static int instanceEncanteur;

	std::vector<std::string> listeMeilleurBid;
	std::string meilleurAcheteur;
	Vendeur* vendeur;
	int meilleurBid;
	int tempsRestant;
	int montantInitial;
	int temps;
	int nbBidMax, nbBidMin,nbBid;
	bool actif;
	void getMontantInitial();

	std::mutex bidLock;

	friend class Encan;

	bool getState() {
		return actif;
	}


public:
	static int venteReussi;

	Encanteur(Vendeur*,int);
	~Encanteur();

	void nouveauBid(int ,std::string);
	bool timeCheck();
	void transactionFinale();
	int getCurrentPrix() {
		if (meilleurBid == 0)
			return montantInitial;
		else
			return meilleurBid;
	}

	void setTemps(int newTemps) {
		if (temps == 0)
			temps = newTemps;
	}

	static const int getNbInstance() {
		return Encanteur::instanceEncanteur;
	}
};

