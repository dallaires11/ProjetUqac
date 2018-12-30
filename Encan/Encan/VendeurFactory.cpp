#include "VendeurFactory.h"

int VendeurFactory::instanceVendeurFac = 0;

VendeurFactory::VendeurFactory(SalleAttente* salle){
	salleAttente = salle;
	objFactory = new ObjetFactory();
	running = false;

	prenom[0] = "Rashissh";
	prenom[1] = "Patrice";
	prenom[2] = "Johanne";
	prenom[3] = "Ayase";
	prenom[4] = "Victor";
	prenom[5] = "Hannibal";
	prenom[6] = "M.";
	prenom[7] = "Lewis";
	prenom[8] = "François";
	prenom[9] = "Roger";

	nom[0] = "de la Maison Krammer";
	nom[1] = "Roberge";
	nom[2] = "Lectur";
	nom[3] = "Gibron";
	nom[4] = "Alpha";
	nom[5] = "Patat";
	nom[6] = "Perron";
	nom[7] = "Dread";
	nom[8] = "Shaliman";
	nom[9] = "Ketchum";

	VendeurFactory::instanceVendeurFac++;
}


VendeurFactory::~VendeurFactory(){
	delete objFactory;
	VendeurFactory::instanceVendeurFac--;
}

std::string VendeurFactory::getNom() {
	std::string leNom = nom[(rand() % 9)];
	return leNom;
}

std::string VendeurFactory::getPrenom() {
	std::string lePrenom = prenom[(rand() % 9)];
	return lePrenom;
}

int VendeurFactory::getTypeVente() {
	int type = (rand() % 3) + 1;
	return type;
}

void VendeurFactory::ajouterVendeur() {
	std::string nom = getNom();
	std::string prenom = getPrenom();
	int type = getTypeVente();
	Objet* objet = objFactory->getObject(type);

	Vendeur* vendeur = new Vendeur(prenom,nom,objet,type);
	//std::cout << vendeur->getInfo() << "\n";
	salleAttente->addVendeur(vendeur);
}

void VendeurFactory::stop() {
	running = false;
	comportement.join();
}

void VendeurFactory::start() {
	running = true;
	comportement = std::thread(&VendeurFactory::run, this);
}

void VendeurFactory::run() {
	while (running) {
		ajouterVendeur();
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}