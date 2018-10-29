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
	CreationDTC* creaDTC = new CreationDTC(usine);
	CreationDTNR* creaDTNR = new CreationDTNR(usine);
	CreationDTR* creaDTR = new CreationDTR(usine);
	Operation6* op6 = new Operation6(creaDTR,creaDTNR);
	Operation5* op5 = new Operation5(creaDTC,creaDTNR);
	Operation4* op4 = new Operation4(creaDTC,op5);
	Operation3* op3 = new Operation3(creaDTR,op4);
	Operation2* op2 = new Operation2(op6,op3);
	Operation1* op1 = new Operation1(creaDTNR,op2);

	sequence->ajouterOperation(op1)
		->ajouterOperation(op2)
		->ajouterOperation(op3)
		->ajouterOperation(op4)
		->ajouterOperation(op5)
		->ajouterOperation(op6)
		->ajouterOperation(creaDTC)
		->ajouterOperation(creaDTNR)
		->ajouterOperation(creaDTR);
	sequence->definirOperationDemarrage(op1);

	return sequence;
}

SequenceOperation* GenerateurSeqOperation::genererSequence1(UsineTraitement* usine) {

	return NULL;
}

SequenceOperation* GenerateurSeqOperation::genererSequence(int seq, UsineTraitement* usine) {
	if (seq == 0) {
		return genererSequence0(usine);
	}
	else if (seq == 1) {
		return genererSequence1(usine);
	}
	else
		std::invalid_argument("Pas une sequence valide");
	return NULL;
}