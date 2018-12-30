#include "AcheteurFactory.h"

int AcheteurFactory::instanceAcheteurFac = 0;

AcheteurFactory::AcheteurFactory(SalleAttente* salle){
	running = false;
	salleAttente = salle;
	setNom();
	AcheteurFactory::instanceAcheteurFac++;
}

AcheteurFactory::~AcheteurFactory(){
	AcheteurFactory::instanceAcheteurFac--;
}

void AcheteurFactory::setNom() {
	prenom[0] = "Sam";
	prenom[1] = "Steven";
	prenom[2] = "Natasha";
	prenom[3] = "Yakimada";
	prenom[4] = "Eric";
	prenom[5] = "Djamal";
	prenom[6] = "Jimmy";
	prenom[7] = "Paul";
	prenom[8] = "Jason";
	prenom[9] = "Maxime";

	nom[0] = "Mraz";
	nom[1] = "Dallaire";
	nom[2] = "Duquette";
	nom[3] = "Morin";
	nom[4] = "Tremblay";
	nom[5] = "Beaufrotton";
	nom[6] = "Abdelaziz";
	nom[7] = "Depardieux";
	nom[8] = "Saque";
	nom[9] = "Trump";
}

void AcheteurFactory::ajouterAcheteur(){
	int millieu, budget, nbBid, bidIncrement;
	int type = getTypeProduit();
	std::string leNom = getNom();
	std::string lePrenom = getPrenom();
	millieu = getMillieuSocial();
	budget = getBudget(millieu);
	nbBid = getNbBid(millieu);
	bidIncrement = getBidIncrement(millieu);
	Acheteur* acheteur = new Acheteur(type,budget,nbBid,bidIncrement,lePrenom,leNom);
	salleAttente->addAcheteur(acheteur);
}

void AcheteurFactory::stop() {
	running = false;
	comportement.join();
}

void AcheteurFactory::start() {
	running = true;
	comportement = std::thread(&AcheteurFactory::run, this);
}


int AcheteurFactory::getMillieuSocial() {
	int  millieu = (rand() % 3) + 1;
	return millieu;
}

int AcheteurFactory::getBudget(int millieu) {
	int budget = ((rand() % 35000) + 10000)*millieu;
	return budget;
}

int AcheteurFactory::getNbBid(int millieu){
	if (millieu == 3) {
		return - 1;
	}
	else {
		int nbBid = ((rand() % 3) + 3)*millieu;
		return nbBid;
	}

	return 0;
}

int AcheteurFactory::getTypeProduit(){
	int  type = (rand() % 3)+1;
	return type;
}

int AcheteurFactory::getBidIncrement(int millieu){
	int increment = ((rand() % 500) + 1)*millieu;
	return increment;
}

std::string AcheteurFactory::getNom() {
	std::string leNom = nom[(rand() % 9)];
	return leNom;
}

std::string AcheteurFactory::getPrenom() {
	std::string lePrenom = prenom[(rand() % 9)];
	return lePrenom;
}

void AcheteurFactory::run() {
	while (running) {
		ajouterAcheteur();
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}