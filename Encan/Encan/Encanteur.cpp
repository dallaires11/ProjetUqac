#include "Encanteur.h"

int Encanteur::instanceEncanteur = 0;

Encanteur::Encanteur(Vendeur* vendeur,int type){
	this->vendeur = vendeur;
	//meilleurAcheteur = nullptr;
	getMontantInitial(type);
	tempsRestant = 2;
	actif = true;
	Encanteur::instanceEncanteur++;	
}

Encanteur::~Encanteur(){
	Encanteur::instanceEncanteur--;
}

void Encanteur::getMontantInitial(int type) {
	switch (type){
	case 1:
		montantInitial = ((ObjetAntique*)vendeur->getObjet())->getValeur();
		break;
	case 2:
		montantInitial = ((ObjetArt*)vendeur->getObjet())->getValeur();
		break;
	case 3:
		montantInitial = ((ObjetService*)vendeur->getObjet())->getValeur();
		break;
	default:
		break;
	}
}

/*void Encanteur::nouveauBid(int montant,Acheteur* biddeur) {
	bidLock.lock();
	if (montant != -1&&actif) {
		if (montant > meilleurBid&&montant > montantInitial) {
			meilleurAcheteur = biddeur;
			meilleurBid = montant;
		}
	}
	bidLock.unlock();
}*/

void Encanteur::transactionFinale() {
	Logger::getInstance()->newLog();
	vendeur->stop();
	return;
}

bool Encanteur::timeCheck() {
	tempsRestant--;
	if (tempsRestant = 0) {
		actif = false;
		transactionFinale();
		return false;
	}
	else
		return true;
}