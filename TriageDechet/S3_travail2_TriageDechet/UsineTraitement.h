#pragma once
#include"SequenceOperation.h"
#include"Depot.h"
#include"ChargementDechet.h"
class UsineTraitement{
private:
	static int instanceUsine;
	SequenceOperation* sequenceOperation;
	Depot depot;
	CamionBleu* camionBleu;
	CamionBrun* camionBrun;
	CamionVert* camionVert;
	void preOperation();
	void postOperation();
	void traiterDTC(Dechet* dechet);
	void traiterDTNR(Dechet* dechet);
	void traiterDTR(Dechet* dechet);
	void traiterDechet(Dechet* dechet);
public:
	UsineTraitement();
	~UsineTraitement();

	void chargerOperation(SequenceOperation* sequenceOperation);
	void demmarerTraitement(ChargementDechet* chargementDechet);

	static const int getNbInstance() {
		return UsineTraitement::instanceUsine;
	}
};