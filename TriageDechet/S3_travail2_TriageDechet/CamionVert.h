#pragma once
#include"Camion.h"
#include"DechetTraiteNonRecyclabe.h"
class CamionVert :
	public Camion {
private:
	static int instanceCamionVert;
public:
	CamionVert();
	CamionVert(const CamionVert&);
	~CamionVert();

	bool ajouterDechet(DechetTraiteNonRecyclabe*);

	static const int getNbInstance() {
		return CamionVert::instanceCamionVert;
	}
};