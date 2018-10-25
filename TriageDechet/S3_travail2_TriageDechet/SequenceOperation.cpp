#include "SequenceOperation.h"

int SequenceOperation::instanceSeqOp = 0;

SequenceOperation::SequenceOperation(){
	instanceSeqOp++;
}

SequenceOperation::~SequenceOperation(){
	instanceSeqOp--;
}

SequenceOperation* SequenceOperation::ajouterOperation(Operation* operation) {
	return NULL;
}

void SequenceOperation::definirOperationDemarrage(Operation*) {

}

Operation* SequenceOperation::getOperation() {

	return NULL;
}