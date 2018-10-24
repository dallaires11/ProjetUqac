#pragma once
#include "Operation.h"
class Operation5 :
	public Operation {
private:
	static int instanceOperation5;
public:
	Operation5(Operation*, Operation*);
	~Operation5();

	bool effectuerOperation(Dechet*);

	static const int getNbInstance() {
		return Operation5::instanceOperation5;
	}
};