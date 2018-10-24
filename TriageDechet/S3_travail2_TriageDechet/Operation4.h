#pragma once
#include "Operation.h"
class Operation4 :
	public Operation {
private:
	static int instanceOperation4;
public:
	Operation4(Operation*, Operation*);
	~Operation4();

	bool effectuerOperation(Dechet*);

	static const int getNbInstance() {
		return Operation4::instanceOperation4;
	}
};