#pragma once
#include "Camion.h"
//#inlucde"DechetTraiteRecyclabe
class CamionBleu :
	public Camion{
private:
	static int instanceCamionBleu;
public:
	CamionBleu();
	~CamionBleu();

	//bool ajouterDechet(DechetTraiteRecyclabe*);

	static const int getNbInstance() {
		return CamionBleu::instanceCamionBleu;
	}
};

