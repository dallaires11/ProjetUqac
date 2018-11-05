#include "Operation6.h"

int Operation6::instanceOperation6 = 0;

Operation6::Operation6(Operation* opTrue, Operation* opFalse) :Operation(opTrue, opFalse) {
	instanceOperation6++;
}

Operation6::Operation6(const Operation6& pseudoOperation) : Operation() {
	instanceOperation6++;
}


Operation6::~Operation6() {
	instanceOperation6--;
}

bool Operation6::effectuerOperation(Dechet* dechet) {
	if(dechet->getTypePlastique()==0||dechet->getTypePlastique()==6)
	return true;
}