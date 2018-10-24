#pragma once
#include "Operation.h"
class Operation1 :
	public Operation{
private:
	static int instanceOperation1;
public:
	Operation1(Operation*,Operation*);
	~Operation1();

	bool effectuerOperation(Dechet*);

	static const int getNbInstance() {
		return Operation1::instanceOperation1;
	}
};