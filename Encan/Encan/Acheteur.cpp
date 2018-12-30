#include "Acheteur.h"

int Acheteur::instanceAcheteur = 0;

Acheteur::Acheteur(int type,int budget,int nbBid,int bidIncrement,std::string prenom,std::string nom){
	this->nom = nom;
	this->prenom = prenom;
	typeProduit = type;
	budgetMax = budget;
	nbBidMax = nbBid;
	currentBidCount = 0;
	this->bidÌncrement = bidIncrement;
	actif = false;

	venteVoulu = nullptr;
	Acheteur::instanceAcheteur++;
}

Acheteur::~Acheteur(){
	Acheteur::instanceAcheteur--;
}

int Acheteur::bidder(int currentPrix) {
	int bid;
	if (currentPrix >= budgetMax || currentBidCount >= nbBidMax){
		stop();
		return -1;
	}
	bid = currentPrix + bidÌncrement;

	if (bid > budgetMax)
		bid = budgetMax;
	currentBidCount++;

	return bid;
}

void Acheteur::stop() {
	actif = false;
}

void Acheteur::run() {
	int currentPrix,bid;

	while (actif&&venteVoulu!=nullptr) {
		currentPrix = 1;//Objet.getCurrentPrix
		//std::cout << bidder(currentPrix);
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
	actif = false;
}

void Acheteur::start(Encanteur* vente) {
	venteVoulu = vente;
	actif = true;
	comportement = std::thread (&Acheteur::run, this);
}

std::string Acheteur::getInfo() {
	std::string desc = "Type " + std::to_string(typeProduit) + " Budget ";
	desc += std::to_string(budgetMax) + " nbBid " + std::to_string(nbBidMax) + " Increment ";
	desc += std::to_string(bidÌncrement) + " Nom " + prenom + " " + nom + "\n";

	return desc;
}