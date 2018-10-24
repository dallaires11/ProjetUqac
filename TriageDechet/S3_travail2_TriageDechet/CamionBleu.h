#pragma once
#include "Camion.h"
#include"DechetTraiteRecyclabe.h"
class CamionBleu :
	public Camion{
private:
	static int instanceCamionBleu;
public:
	CamionBleu();
	~CamionBleu();

	bool ajouterDechet(DechetTraiteRecyclabe*);

	static const int getNbInstance() {
		return CamionBleu::instanceCamionBleu;
	}
};