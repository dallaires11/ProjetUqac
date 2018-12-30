#include "SalleAttente.h"

int SalleAttente::instanceSalleAtt = 0;

SalleAttente::SalleAttente(){
	currentAcheteur = 0;
	currentVendeur = 0;
	vendeurInactif = 0;
	acheteurInactif = 0;
	SalleAttente::instanceSalleAtt++;
}


SalleAttente::~SalleAttente(){
	fermeture();
	SalleAttente::instanceSalleAtt--;
}

void SalleAttente::getSize() {
	std::cout<<"Acheteurs: "<< fileAcheteur.size() <<" Vendeurs: "<<fileVendeur.size()<< "\n";
}

void SalleAttente::fermeture() {
	Acheteur* a;
	Vendeur* v;
	while (!fileAcheteur.empty()) {
		a = fileAcheteur.back();
		a->join();
		fileAcheteur.pop_back();
		delete a;
	}
	while (!fileVendeur.empty()) {
		v = fileVendeur.back();
		v->join();
		fileVendeur.pop_back();	
		delete v;
	}
}