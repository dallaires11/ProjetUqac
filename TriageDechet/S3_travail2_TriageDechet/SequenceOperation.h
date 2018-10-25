#pragma once
#include"Operation.h"
class SequenceOperation{
private:
	static int instanceSeqOp;
	int currentAjout;
	Operation* operationDemarrage;
	Operation* listeOperation[9];
public:
	SequenceOperation();
	~SequenceOperation();

	SequenceOperation* ajouterOperation(Operation*);
	void definirOperationDemarrage(Operation*);
	Operation* getOperation();

	static const int getNbInstance() {
		return SequenceOperation::instanceSeqOp;
	}
};