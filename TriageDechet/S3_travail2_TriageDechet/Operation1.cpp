#include "Operation1.h"

int Operation1::instanceOperation1 = 0;

Operation1::Operation1(Operation* opTrue,Operation* opFalse):Operation(opTrue,opFalse){
	instanceOperation1++;
}

Operation1::~Operation1(){
	instanceOperation1--;
}

bool Operation1::effectuerOperation(Dechet* dechet) {
	if (dechet->estEnStyromousse() || dechet->estRigide())
		return true;
	else
		return false;
}