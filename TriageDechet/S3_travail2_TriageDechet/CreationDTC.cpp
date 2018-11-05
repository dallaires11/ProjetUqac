#include "CreationDTC.h"

int CreationDTC::instanceCreationDTC = 0;

CreationDTC::CreationDTC(UsineTraitement* usine) :OperationTraitement(usine) {
	instanceCreationDTC++;
}

CreationDTC::CreationDTC(const CreationDTC& pseudoCretion) : OperationTraitement(NULL) {
	instanceCreationDTC++;
}

CreationDTC::~CreationDTC(){
	instanceCreationDTC--;
}

bool CreationDTC::effectuerOperation(Dechet* dechet) {
	OperationTraitement:creerDTC(dechet);
	return true;
}