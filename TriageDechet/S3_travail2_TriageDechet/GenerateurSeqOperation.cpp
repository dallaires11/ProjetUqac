#include "GenerateurSeqOperation.h"

int GenerateurSeqOperation::instanceGenSeqOp = 0;

GenerateurSeqOperation::GenerateurSeqOperation(){
	instanceGenSeqOp++;
}


GenerateurSeqOperation::~GenerateurSeqOperation(){
	instanceGenSeqOp--;
}

SequenceOperation* GenerateurSeqOperation::genererSequence0(UsineTraitement* usine) {
	SequenceOperation* sequence = new SequenceOperation();
	return NULL;
}

SequenceOperation* GenerateurSeqOperation::genererSequence1(UsineTraitement* usine) {

	return NULL;
}

SequenceOperation* GenerateurSeqOperation::genererSequence(int seq, UsineTraitement* usine) {
	if (seq = 0) {
		return genererSequence0(usine);
	}
	else if (seq = 1) {
		return genererSequence1(usine);
	}
	else
		throw;
}