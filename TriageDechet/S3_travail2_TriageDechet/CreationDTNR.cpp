#include "CreationDTNR.h"

int CreationDTNR::instanceCreationDTNR = 0;

CreationDTNR::CreationDTNR(UsineTraitement* usine) :OperationTraitement(usine) {
	instanceCreationDTNR++;
}

CreationDTNR::CreationDTNR(const CreationDTNR& pseudoCretion) : OperationTraitement(NULL) {
	instanceCreationDTNR++;
}

CreationDTNR::~CreationDTNR() {
	instanceCreationDTNR--;
}

bool CreationDTNR::effectuerOperation(Dechet* dechet) {
	OperationTraitement:creerDTNR(dechet);
	return true;
}