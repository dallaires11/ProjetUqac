#pragma once
#include "Camion.h"
//#inlucde"DechetTraiteCompostable"
class CamionBrun :
	public Camion{
private:
	static int instanceCamionBrun;
public:
	CamionBrun();
	~CamionBrun();

	//bool ajouterDechet(DechetTraiteCompostable*);

	static const int getNbInstance() {
		return CamionBrun::instanceCamionBrun;
	}
};

