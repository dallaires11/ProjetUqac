#pragma once
#include"Camion.h"
//#inlucde"DechetTraiteNonRecyclabe
class CamionVert :
	public Camion {
private:
	static int instanceCamionVert;
public:
	CamionVert();
	~CamionVert();

	//bool ajouterDechet(DechetTraiteNonRecyclabe*);

	static const int getNbInstance() {
		return CamionVert::instanceCamionVert;
	}
};

