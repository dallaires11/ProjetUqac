#pragma once
#include<string>
#include<thread>
#include"Encanteur.h"
#include<iostream>
class Acheteur final{
private:
	static int instanceAcheteur;

	int budgetMax,nbBidMax,bidÌncrement,currentBidCount, typeProduit;
	std::string nom, prenom;
	std::thread comportement;
	bool actif;
	
	int bidder(int);
	void run();
	void stop();

	Encanteur* venteVoulu;

public:
	Acheteur(int,int,int,int,std::string,std::string);
	~Acheteur();

	void start(Encanteur*);

	int getType() {
		return typeProduit;
	}

	void join() {
		if (actif) {
			stop();
			comportement.join();
		}
	}

	static const int getNbInstance() {
		return Acheteur::instanceAcheteur;
	}

	std::string getInfo();
};

