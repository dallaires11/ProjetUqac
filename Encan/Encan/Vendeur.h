#pragma once
#include"Objet.h"
#include<thread>
class Vendeur final{
	static int instanceVendeur;

	Objet* objet;
	int typeVente;
	std::string nom;
	std::string prenom;
	std::thread comportement;
	bool actif;

	void run();
public:
	Vendeur(std::string,std::string,Objet*,int);
	~Vendeur();

	Objet* getObjet();

	int getType() {
		return typeVente;
	}

	static const int getNbInstance() {
		return Vendeur::instanceVendeur;
	}

	bool isActif() {
		return actif;
	}

	void start();
	void stop();

	void join() {
		if (actif) {
			stop();
			comportement.join();
		}
			
	}

	std::string getInfo();
};