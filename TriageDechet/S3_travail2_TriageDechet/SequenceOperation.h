#pragma once
#include"Operation.h"
class SequenceOperation{
private:
	static int instanceSeqOp;
	Operation* operationDemarrage;
	Operation* listeOperation;
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