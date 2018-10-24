#include "OperationTraitement.h"

int OperationTraitement::instanceOperationTraitement = 0;

OperationTraitement::OperationTraitement(UsineTraitement* pseudoUsineTraitement):Operation(){
	usineTraitment = pseudoUsineTraitement;
	instanceOperationTraitement++;
}


OperationTraitement::~OperationTraitement(){
	delete usineTraitment;
	instanceOperationTraitement--;
}

void OperationTraitement::creerDTR(Dechet* dechet) {
	
}

void OperationTraitement::creerDTNR(Dechet* dechet) {

}

void OperationTraitement::creerDTC(Dechet* dechet) {

}

bool OperationTraitement::effectuerOperation(Dechet* dechet) {
	return true;
}