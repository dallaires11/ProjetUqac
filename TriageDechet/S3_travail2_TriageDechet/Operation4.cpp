#include "Operation4.h"

int Operation4::instanceOperation4 = 0;

Operation4::Operation4(Operation* opTrue, Operation* opFalse) :Operation(opTrue, opFalse) {
	instanceOperation4++;
}


Operation4::~Operation4() {
	instanceOperation4--;
}

bool Operation4::effectuerOperation(Dechet* dechet) {
	if (dechet->getMateriel() == 6 && dechet->getCouleur() == "brun")
		return true;
	else
		return false;
}
