#include "Operation3.h"

int Operation3::instanceOperation3 = 0;

Operation3::Operation3(Operation* opTrue, Operation* opFalse) :Operation(opTrue, opFalse) {
	instanceOperation3++;
}


Operation3::~Operation3() {
	instanceOperation3--;
}

bool Operation3::effectuerOperation(Dechet* dechet) {
	return true;
}