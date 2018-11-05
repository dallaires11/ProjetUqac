#pragma once
#include "Operation.h"
class Operation6 :
	public Operation {
private:
	static int instanceOperation6;
public:
	Operation6(Operation*, Operation*);
	Operation6(const Operation6&);
	~Operation6();

	bool effectuerOperation(Dechet*);

	static const int getNbInstance() {
		return Operation6::instanceOperation6;
	}
};