#include "Encan.h"

Encan* Encan::instance = 0;

Encan::Encan(){
	encheresAntique = nullptr;
	tailleEnchereAntique = 0;
	encheresArt = nullptr;
	tailleEnchereArt = 0;
	encheresService = nullptr;
	tailleEnchereService = 0;
}

Encan* Encan::getInstance(){
	if (instance == 0){
		instance = new Encan();
	}
	return instance;
}

void Encan::fermeture(){
	enchere* currentEnchere = encheresAntique;
	enchere* enchere;
	while (tailleEnchereAntique != 0) {
		enchere = currentEnchere;
		currentEnchere = currentEnchere->next;
		delete enchere->encanteur;
		delete enchere;
		tailleEnchereAntique--;
	}
	currentEnchere = encheresArt;
	while (tailleEnchereArt != 0) {
		enchere = currentEnchere;
		currentEnchere = currentEnchere->next;
		delete enchere->encanteur;
		delete enchere;
		tailleEnchereArt--;
	}
	currentEnchere = encheresService;
	while (tailleEnchereService != 0) {
		enchere = currentEnchere;
		currentEnchere = currentEnchere->next;
		delete enchere->encanteur;
		delete enchere;
		tailleEnchereService--;
	}
}