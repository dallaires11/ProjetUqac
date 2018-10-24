#include "Operation.h"

int Operation::instanceOperation = 0;

Operation::Operation(){
	instanceOperation++;
}

Operation::Operation(Operation* opSuivTrue, Operation* opSuivFalse) {
	operationSuivanteTrue = opSuivTrue;
	operationSuivanteFalse = opSuivFalse;
	instanceOperation++;
}

Operation::~Operation(){
	delete operationSuivanteTrue;
	delete operationSuivanteFalse;
	instanceOperation--;
}

bool Operation::effectuerOperation(Dechet* dechet) {
	return getOperationSuivante(true);
}

Operation* Operation::getOperationSuivante(bool choix) {
	if (choix)//choix==true
		return operationSuivanteTrue;
	else
		return operationSuivanteFalse;
}