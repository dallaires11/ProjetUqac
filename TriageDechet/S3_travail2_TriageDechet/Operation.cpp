#include "Operation.h"

int Operation::instanceOperation = 0;

Operation::Operation(){
	operationSuivanteTrue = NULL;
	operationSuivanteFalse = NULL;
	instanceOperation++;
}

Operation::Operation(Operation* opSuivTrue, Operation* opSuivFalse) {
	operationSuivanteTrue = opSuivTrue;
	operationSuivanteFalse = opSuivFalse;
	instanceOperation++;
}

Operation::Operation(const Operation& pseudoOperation) {
	operationSuivanteFalse = pseudoOperation.operationSuivanteFalse;
	operationSuivanteTrue = pseudoOperation.operationSuivanteTrue;
	instanceOperation++;
}

Operation::~Operation(){
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