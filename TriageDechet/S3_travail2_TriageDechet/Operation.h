#pragma once
#include"Dechet.h"
class Operation{
private:
	static int instanceOperation;

	Operation* operationSuivanteTrue;
	Operation* operationSuivanteFalse;
protected:
	Operation();
public:
	Operation(Operation*,Operation*);
	Operation(const Operation&);
	virtual ~Operation();

	virtual bool effectuerOperation(Dechet*);

	Operation* getOperationSuivante(bool);

	static const int getNbInstance() {
		return Operation::instanceOperation;
	}
};

