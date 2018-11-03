#pragma once
#include"Operation.h"
#include<list>
class SequenceOperation{
private:
	static int instanceSeqOp;
	int currentAjout;
	Operation* operationDemarrage;
	std::list<Operation*> listeOperation;
	void destroyOperation();
public:
	SequenceOperation();
	~SequenceOperation();

	SequenceOperation* ajouterOperation(Operation*);
	void definirOperationDemarrage(Operation*);

	Operation* getOperation() {
		return operationDemarrage;
	}

	static const int getNbInstance() {
		return SequenceOperation::instanceSeqOp;
	}
};