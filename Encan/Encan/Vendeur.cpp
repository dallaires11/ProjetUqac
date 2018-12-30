#include "Vendeur.h"

int Vendeur::instanceVendeur = 0;

Vendeur::Vendeur(std::string prenom,std::string nom,Objet* objet,int type){
	Vendeur::instanceVendeur++;
	this->prenom = prenom;
	this->nom = nom;
	this->objet = objet;
	typeVente = type;
	actif = false;
}

Vendeur::~Vendeur(){
	delete objet;
	Vendeur::instanceVendeur--;
}

void Vendeur::stop() {
	actif = false;
	//printf("Arret\n");
}

void Vendeur::run() {
	//printf("Start\n");
	while (actif) {
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
	//printf("Arreter\n");
}

void Vendeur::start() {
	actif = true;
	//printf("Signal start Start\n");
	comportement = std::thread(&Vendeur::run, this);
}

std::string Vendeur::getInfo() {
	return prenom + " " + nom + " " + objet->getInfo();
}

Objet* Vendeur::getObjet() {
	return objet;
}