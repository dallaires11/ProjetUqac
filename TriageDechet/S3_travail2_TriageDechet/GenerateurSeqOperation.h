#pragma once
#include"SequenceOperation.h"
#include"UsineTraitement.h"
class GenerateurSeqOperation{
private:
	static int instanceGenSeqOp;
	SequenceOperation* genererSequence0(UsineTraitement*);
	SequenceOperation* genererSequence1(UsineTraitement*);//Fonction de test
public:
	GenerateurSeqOperation();
	~GenerateurSeqOperation();

	SequenceOperation* genererSequence(UsineTraitement*);

	static const int getNbInstance() {
		return GenerateurSeqOperation::instanceGenSeqOp;
	}
};