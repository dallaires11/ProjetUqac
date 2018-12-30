#pragma once
#include"Vendeur.h"
#include"Logger.h"
//#include"Acheteur.h"
#include"ObjetAntique.h"
#include"ObjetArt.h"
#include"ObjetService.h"
#include<mutex>
class Encanteur{
private:
	static int instanceEncanteur;

	//Acheteur* meilleurAcheteur;
	Vendeur* vendeur;
	int meilleurBid;
	int tempsRestant;
	int montantInitial;
	bool actif;
	void getMontantInitial(int);

	std::mutex bidLock;


public:
	Encanteur(Vendeur*,int);
	~Encanteur();

	//void nouveauBid(int ,Acheteur*);
	bool timeCheck();
	void transactionFinale();

	static const int getNbInstance() {
		return Encanteur::instanceEncanteur;
	}
};

