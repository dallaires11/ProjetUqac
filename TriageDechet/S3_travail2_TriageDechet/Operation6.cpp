#include "Operation6.h"

int Operation6::instanceOperation6 = 0;

Operation6::Operation6(Operation* opTrue, Operation* opFalse) :Operation(opTrue, opFalse) {
	instanceOperation6++;
}


Operation6::~Operation6() {
	instanceOperation6--;
}

bool Operation6::effectuerOperation(Dechet* dechet) {
	return true;
}