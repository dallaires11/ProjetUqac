#pragma once
#include "Operation.h"
#include "UsineTraitement.h"
class OperationTraitement :
	public Operation{
private:
	static int instanceOperationTraitement;
	UsineTraitement* usineTraitment;
protected:
	void creerDTR(Dechet*);
	void creerDTNR(Dechet*);
	void creerDTC(Dechet*);
public:
	OperationTraitement(UsineTraitement*);
	~OperationTraitement();

	bool effectuerOperation(Dechet*);
	Operation* getOperationSuivante(bool choix);


	static const int getNbInstance() {
		return OperationTraitement::instanceOperationTraitement;
	}
};

