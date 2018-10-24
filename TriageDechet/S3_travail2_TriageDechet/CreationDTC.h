#pragma once
#include "OperationTraitement.h"
class CreationDTC :
	public OperationTraitement{
private:
	static int instanceCreationDTC;
public:
	CreationDTC(UsineTraitement*);
	~CreationDTC();

	bool effectuerOperation(Dechet*);

	static const int getNbInstance() {
		return CreationDTC::instanceCreationDTC;
	}
};