#pragma once
#include "Operation.h"
class Operation3 :
	public Operation {
private:
	static int instanceOperation3;
public:
	Operation3(Operation*, Operation*);
	Operation3(const Operation3&);
	~Operation3();

	bool effectuerOperation(Dechet*);

	static const int getNbInstance() {
		return Operation3::instanceOperation3;
	}
};