#include "Operation5.h"

int Operation5::instanceOperation5 = 0;

Operation5::Operation5(Operation* opTrue, Operation* opFalse) :Operation(opTrue, opFalse) {
	instanceOperation5++;
}


Operation5::~Operation5() {
	instanceOperation5--;
}

bool Operation5::effectuerOperation(Dechet* dechet) {
	return true;
}