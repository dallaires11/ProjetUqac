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
	if (currentAjout < 9) {
		listeOperation[currentAjout] = operation;
		currentAjout++;
	}
	return this;
}

void SequenceOperation::definirOperationDemarrage(Operation* pseudoOperation) {
	operationDemarrage = pseudoOperation;
	return;
}

Operation* SequenceOperation::getOperation() {

	return NULL;
}