#pragma once
#include "Operation.h"
class Operation2 :
	public Operation {
private:
	static int instanceOperation2;
public:
	Operation2(Operation*, Operation*);
	Operation2(const Operation2&);
	~Operation2();

	bool effectuerOperation(Dechet*);

	static const int getNbInstance() {
		return Operation2::instanceOperation2;
	}
};