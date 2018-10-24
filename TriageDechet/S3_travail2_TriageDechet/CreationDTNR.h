#pragma once
#include "OperationTraitement.h"
class CreationDTNR :
	public OperationTraitement {
private:
	static int instanceCreationDTNR;
public:
	CreationDTNR(UsineTraitement*);
	~CreationDTNR();

	bool effectuerOperation(Dechet*);

	static const int getNbInstance() {
		return CreationDTNR::instanceCreationDTNR;
	}
};