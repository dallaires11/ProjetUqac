#include "ObjetService.h"

int ObjetService::instanceObjetService = 0;

ObjetService::ObjetService(int prixDepart,int tarifBase,int experience,std::string description):Objet(prixDepart){
	this->fraisBase = prixDepart;
	this->tarifBase = tarifBase;
	this->experience = experience;
	serviceDesc = description;
	ObjetService::instanceObjetService++;
}

ObjetService::~ObjetService(){
	ObjetService::instanceObjetService--;
}

std::string ObjetService::getInfo() {
	return serviceDesc;
}