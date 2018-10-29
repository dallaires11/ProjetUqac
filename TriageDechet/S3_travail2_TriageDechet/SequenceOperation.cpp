#include "SequenceOperation.h"

int SequenceOperation::instanceSeqOp = 0;

SequenceOperation::SequenceOperation(){
	currentAjout = 0;
	instanceSeqOp++;
}

SequenceOperation::~SequenceOperation(){
	instanceSeqOp--;
}

SequenceOperation* SequenceOperation::ajouterOperation(Operation* operation) {
	listeOperation.push_back(operation);
	return this;
}

void SequenceOperation::definirOperationDemarrage(Operation* pseudoOperation) {
	operationDemarrage = pseudoOperation;
	return;
}

Operation* SequenceOperation::getOperation() {

	return NULL;
}

void SequenceOperation::destroyOperation() {
	Operation* operation = nullptr;
	while (!listeOperation.empty())
	{
		operation = listeOperation.front();
		listeOperation.pop_front();
		delete operation;
	}
	//delete listeDechet;

	return;
}