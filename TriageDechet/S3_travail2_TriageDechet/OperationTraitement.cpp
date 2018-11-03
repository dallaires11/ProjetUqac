#include "OperationTraitement.h"

int OperationTraitement::instanceOperationTraitement = 0;

OperationTraitement::OperationTraitement(UsineTraitement* pseudoUsineTraitement):Operation(){
	usineTraitment = pseudoUsineTraitement;
	instanceOperationTraitement++;
}


OperationTraitement::~OperationTraitement(){
	instanceOperationTraitement--;
}

void OperationTraitement::creerDTR(Dechet* dechet) {
	usineTraitment->traiterDTR(dechet);
}

void OperationTraitement::creerDTNR(Dechet* dechet) {
	usineTraitment->traiterDTNR(dechet);
}

void OperationTraitement::creerDTC(Dechet* dechet) {
	usineTraitment->traiterDTC(dechet);
}

bool OperationTraitement::effectuerOperation(Dechet* dechet) {
	return true;
}

Operation* OperationTraitement::getOperationSuivante(bool choix) {
	return NULL;
}