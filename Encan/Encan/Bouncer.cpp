#include "Bouncer.h"

int Bouncer::instanceBouncer = 0;

Bouncer::Bouncer(SalleAttente* salle){
	salleAtt = salle;
	running = false;
	Bouncer::instanceBouncer++;
}

Bouncer::~Bouncer(){
	Bouncer::instanceBouncer--;
}

void Bouncer::addNewAntiqueVendeur(Vendeur* vendeur) {
	enchere* vente = new enchere;
	Encanteur* newEncanteur = new Encanteur(vendeur, 1);
	vente->encanteur = newEncanteur;
	if (Encan::getInstance()->tailleEnchereAntique==0) {
		Encan::getInstance()->encheresAntique = vente;
	}
	else {
		enchere* currentEnchere = Encan::getInstance()->encheresAntique;
		while (currentEnchere->next != nullptr) {
			currentEnchere = currentEnchere->next;
		}
		currentEnchere->next = vente;
	}
	vendeur->start();
	Encan::getInstance()->tailleEnchereAntique++;
}

void Bouncer::addNewArtVendeur(Vendeur* vendeur) {
	enchere* vente = new enchere;
	Encanteur* newEncanteur = new Encanteur(vendeur, 2);
	vente->encanteur = newEncanteur;
	if (Encan::getInstance()->tailleEnchereArt==0) {
		Encan::getInstance()->encheresArt = vente;
	}
	else {
		enchere* currentEnchere = Encan::getInstance()->encheresArt;
		while (currentEnchere->next != nullptr) {
			currentEnchere = currentEnchere->next;
		}
		currentEnchere->next = vente;
	}
	vendeur->start();
	Encan::getInstance()->tailleEnchereArt++;
}

void Bouncer::addNewServiceVendeur(Vendeur* vendeur) {
	enchere* vente = new enchere;
	Encanteur* newEncanteur = new Encanteur(vendeur, 3);
	vente->encanteur = newEncanteur;
	if (Encan::getInstance()->tailleEnchereService==0) {
		Encan::getInstance()->encheresService = vente;
	}
	else {
		enchere* currentEnchere = new enchere;
		currentEnchere = Encan::getInstance()->encheresService;
		while (currentEnchere->next != nullptr) {
			currentEnchere = currentEnchere->next;
		}
		currentEnchere->next = vente;
	}
	vendeur->start();
	Encan::getInstance()->tailleEnchereService++;
}

void Bouncer::inviterVendeur() {
	Vendeur* vendeur = salleAtt->getNextVendeur();
	switch (vendeur->getType()){
		case 1:
			addNewAntiqueVendeur(vendeur);
			break;
		case 2:
			addNewArtVendeur(vendeur);
			break;
		case 3:
			addNewServiceVendeur(vendeur);
			break;
		default:
			break;
	}
}

void Bouncer::addNewAntiqueAcheteur(Acheteur* acheteur) {
	int range = Encan::getInstance()->tailleEnchereAntique;
	if (range != 0) {
		int positionVente = (rand() % range);
		int currentPosition = 0;
		enchere* vente = Encan::getInstance()->encheresAntique;
		while (currentPosition != positionVente) {
			vente = vente->next;
			currentPosition++;
		}
		acheteur->start(vente->encanteur);
	}
}

void Bouncer::addNewArtAcheteur(Acheteur* acheteur) {
	int range = Encan::getInstance()->tailleEnchereArt;
	if (range != 0) {
		int positionVente = (rand() % range);
		int currentPosition = 0;
		enchere* vente = Encan::getInstance()->encheresArt;
		while (currentPosition != positionVente) {
			vente = vente->next;
			currentPosition++;
		}
		acheteur->start(vente->encanteur);
	}
}

void Bouncer::addNewServiceAcheteur(Acheteur* acheteur) {
	int range = Encan::getInstance()->tailleEnchereService;
	if (range != 0) {
		int positionVente = (rand() % range);
		int currentPosition = 0;
		enchere* vente = Encan::getInstance()->encheresService;
		while (currentPosition != positionVente) {
			vente = vente->next;
			currentPosition++;
		}
		acheteur->start(vente->encanteur);
	}
}

void Bouncer::inviterAcheteur() {
	Acheteur* acheteur = salleAtt->getNextAcheteur();
	switch (acheteur->getType()){
		case 1:
			addNewAntiqueAcheteur(acheteur);
			break;
		case 2:
			addNewArtAcheteur(acheteur);
			break;
		case 3:
			addNewServiceAcheteur(acheteur);
			break;
		default:
			break;
	}
}

void Bouncer::stop() {
	running = false;
	comportement.join();
}

void Bouncer::start() {
	running = true;
	comportement = std::thread(&Bouncer::run, this);
}

void Bouncer::run() {
	int x = 0;
	while (running&&x<6) {
		inviterVendeur();
		x++;
		std::this_thread::sleep_for(std::chrono::seconds(3));
	}
	while (running) {
		inviterVendeur();
		inviterAcheteur();
		inviterAcheteur();
		std::this_thread::sleep_for(std::chrono::seconds(3));
	}
}