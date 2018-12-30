#include "ObjetFactory.h"

int ObjetFactory::instanceObjetFactory = 0;

ObjetFactory::ObjetFactory(){
	typeArt[0] = "Tableau";
	typeArt[1] = "Sculpture";
	typeArt[2] = "DevoirPOO";

	typeEtat[0] = "tres deteriore";
	typeEtat[1] = "moderement conserve";
	typeEtat[2] = "miraculeusement comme neuf";

	periode[0] = "provenant du dernier Expo mondial";
	periode[1] = "du temps des croisades";
	periode[2] = "datant de la pre histoire";

	typeService[0] = "Service de plomberie";
	typeService[1] = "Support Maximo (2 ans)";
	typeService[2] = "Contrat de servitude (duree indefini)";
	typeService[3] = "Livraison de pizza";
	typeService[4] = "Service de communication avec les spheres sombres";

	ObjetFactory::instanceObjetFactory++;
}

ObjetFactory::~ObjetFactory(){
	ObjetFactory::instanceObjetFactory--;
}

std::string ObjetFactory::getDescriptionArt(int renomme, int dimension, std::string type) {
	std::string desc = type + " de ";
	desc += std::to_string(dimension)+ "x" + std::to_string(dimension)+ "x" + std::to_string(dimension);
	if (renomme >= 75)
		desc += " qui est bien cotte ";
	else if (renomme >= 25)
		desc += " qui est moyennement cotte";
	else
		desc += " qui est mal cotte";
	return desc;
}

int ObjetFactory::getValeurArt(int renomme) {
	int valeur = rand() %(200*renomme) +1000;
	return valeur;
}

int ObjetFactory::getDimmension() {
	int dimmension = (rand() % 15) + 1;
	return dimmension;
}

int ObjetFactory::getRenomme() {
	int renomme = (rand() % 100) + 1;
	return renomme;
}

std::string ObjetFactory::getTypeArt(){
	std::string type = typeArt[rand()%3];
	return type;
}

ObjetArt* ObjetFactory::getObjetArt() {
	int renomme,dimmension,valeur;
	std::string typeArt, description;
	typeArt = getTypeArt();
	renomme = getRenomme();
	dimmension = getDimmension();
	valeur = getValeurArt(renomme);
	description = getDescriptionArt(renomme,dimmension,typeArt);

	return new ObjetArt(valeur,renomme,dimmension,description);
}

int ObjetFactory::getPeriode(){
	int periode = rand() % 3;
	return periode;
}

int ObjetFactory::getTypeEtat() {
	int etat = rand() % 3;
	return etat;
}

int ObjetFactory::getValeurOld(int periode, int etat) {
	int valeur = ((rand() % 3000) + ((periode + 1) * 1000)) + (etat*2000);
	return valeur;
}

std::string ObjetFactory::getDescriptionOld(int periode, int etat) {
	std::string desc = "Artefact " + this->periode[periode];
	desc += " " + typeEtat[etat];
	return desc;
}

ObjetAntique* ObjetFactory::getObjetAntique() {
	int valeur, periode, etat;
	std::string desc;
	periode = getPeriode();
	etat = getTypeEtat();
	valeur = getValeurOld(periode,etat);
	desc = getDescriptionOld(periode,etat);

	return new ObjetAntique(valeur,this->periode[periode], typeEtat[etat],desc);
}

int ObjetFactory::getTypeService() {
	int typeService = (rand() % 5);
	return typeService;
}

int ObjetFactory::getExperience() {
	int experience = (rand() % 30);
	return experience;
}

int ObjetFactory::getTarif(int experience) {
	int tarif = 15+(rand() % 15)+experience;
	return tarif;
}

int ObjetFactory::getValeurService(int experience) {
	int valeur = (rand() % (100*(experience+1)))+1500;
	return valeur;
}

std::string ObjetFactory::getDescriptionService(int typeService,int experience,int tarif) {
	std::string desc = this->typeService[typeService] + " execute par quelqun ayant ";
	desc += std::to_string(experience) + " ans d'experience pour ";
	desc += std::to_string(tarif)+"$ de l'heure";
	return desc;
}

ObjetService* ObjetFactory::getObjetService() {
	int valeur, typeService, experience, tarif;
	std::string description;
	typeService = getTypeService();
	experience = getExperience();
	tarif = getTarif(experience);
	valeur = getValeurService(experience);
	description = getDescriptionService(typeService,experience,tarif);

	return new ObjetService(valeur, tarif, experience, description);
}

Objet* ObjetFactory::getObject(int type) {
	if (type == 1)
		return getObjetService();
	else if (type == 2)
		return getObjetArt();
	else
		return getObjetAntique();
}