#include "CreationDTR.h"

int CreationDTR::instanceCreationDTR = 0;

CreationDTR::CreationDTR(UsineTraitement* usine) :OperationTraitement(usine) {
	instanceCreationDTR++;
}

CreationDTR::~CreationDTR() {
	instanceCreationDTR--;
}

bool CreationDTR::effectuerOperation(Dechet* dechet) {
	OperationTraitement::creerDTR(dechet);
	return true;
}