#pragma once
#include "OperationTraitement.h"
class CreationDTR :
	public OperationTraitement {
private:
	static int instanceCreationDTR;
public:
	CreationDTR(UsineTraitement*);
	~CreationDTR();

	bool effectuerOperation(Dechet*);

	static const int getNbInstance() {
		return CreationDTR::instanceCreationDTR;
	}
};