#pragma once
#include "Camion.h"
#include"DechetTraiteCompostable.h"
class CamionBrun :
	public Camion{
private:
	static int instanceCamionBrun;
public:
	CamionBrun();
	CamionBrun(const CamionBrun&);
	~CamionBrun();

	bool ajouterDechet(DechetTraiteCompostable*);

	static const int getNbInstance() {
		return CamionBrun::instanceCamionBrun;
	}
};