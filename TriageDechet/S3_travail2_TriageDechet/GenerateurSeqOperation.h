#pragma once
#include"UsineTraitement.h"
#include"Operation1.h"
#include"Operation2.h"
#include"Operation3.h"
#include"Operation4.h"
#include"Operation5.h"
#include"Operation6.h"
#include"CreationDTC.h"
#include"CreationDTR.h"
#include"CreationDTNR.h"
class GenerateurSeqOperation{
private:
	static int instanceGenSeqOp;
	SequenceOperation* genererSequence0(UsineTraitement*);
	SequenceOperation* genererSequence1(UsineTraitement*);//Fonction de test
public:
	GenerateurSeqOperation();
	~GenerateurSeqOperation();

	SequenceOperation* genererSequence(int,UsineTraitement*);

	static const int getNbInstance() {
		return GenerateurSeqOperation::instanceGenSeqOp;
	}
};