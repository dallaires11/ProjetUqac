#include "Encanteur.h"

int Encanteur::instanceEncanteur = 0;
int Encanteur::venteReussi = 0;

Encanteur::Encanteur(Vendeur* vendeur,int type){
	this->vendeur = vendeur;
	meilleurAcheteur = "";
	meilleurBid = 0;
	getMontantInitial();
	tempsRestant = 35;
	actif = true;
	nbBidMax = 10;
	nbBidMin = 1;
	nbBid = 0;
	Encanteur::instanceEncanteur++;	
}

Encanteur::~Encanteur(){
	Encanteur::instanceEncanteur--;
}

void Encanteur::getMontantInitial() {
	montantInitial = (vendeur->getObjet())->getValeur();
}

void Encanteur::nouveauBid(int montant,std::string nom) {
	bidLock.lock();
	if (actif) {
		nbBid++;
		//printf("aaad");
		if (montant > meilleurBid&&montant > montantInitial) {
			meilleurAcheteur = nom;
			listeMeilleurBid.push_back(nom);
			meilleurBid = montant;
		}
		if (nbBid >= nbBidMax) {
			actif = false;
			transactionFinale();
		}
	}
	bidLock.unlock();
}

void Encanteur::transactionFinale() {
	if(meilleurAcheteur=="")
		Logger::getInstance()->newLog(vendeur->getInfo());
	else {
		Logger::getInstance()->newLog(meilleurAcheteur, vendeur->getInfo(), meilleurBid);
		Encanteur::venteReussi++;
	}
	
	vendeur->stop();
	return;
}

bool Encanteur::timeCheck() {
	tempsRestant--;
	if (tempsRestant == 0&&actif) {
		actif = false;
		transactionFinale();
		return false;
	}
	else
		return true;
}