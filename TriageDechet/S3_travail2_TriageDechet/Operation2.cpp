#include "Operation2.h"

int Operation2::instanceOperation2 = 0;

Operation2::Operation2(Operation* opTrue, Operation* opFalse) :Operation(opTrue, opFalse) {
	instanceOperation2++;
}


Operation2::~Operation2() {
	instanceOperation2--;
}

bool Operation2::effectuerOperation(Dechet* dechet) {
	return true;
}