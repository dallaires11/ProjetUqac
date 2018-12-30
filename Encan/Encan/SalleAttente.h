#pragma once
#include<vector>
#include"Acheteur.h"
#include"Vendeur.h"
class SalleAttente{
private:
	static int instanceSalleAtt;

	std::vector<Acheteur*> fileAcheteur;
	std::vector<Vendeur*> fileVendeur;

	int acheteurInactif;
	int vendeurInactif;
	int currentAcheteur;
	int currentVendeur;

	void fermeture();

public:
	SalleAttente();
	~SalleAttente();

	void getSize();
	Acheteur* getNextAcheteur() {
		Acheteur* acheteur = fileAcheteur.at(currentAcheteur);
		acheteurInactif--;
		currentAcheteur++;
		return acheteur;
	}

	Vendeur* getNextVendeur() {
		Vendeur* vendeur = fileVendeur.at(currentVendeur);
		vendeurInactif--;
		currentVendeur++;
		return vendeur;
	}

	void addAcheteur(Acheteur* acheteur) {
		if (acheteurInactif < 20) {
			fileAcheteur.push_back(acheteur);
			acheteurInactif++;
		}
		else
			delete acheteur;
	}
	void addVendeur(Vendeur* vendeur) {
		if (vendeurInactif<20){
			fileVendeur.push_back(vendeur);
			vendeurInactif++;
		}
		else
			delete vendeur;
	}

	static int getNbIntance() {
		return SalleAttente::instanceSalleAtt;
	}
};

