#include "CamionBleu.h"

int CamionBleu::instanceCamionBleu = 0;

CamionBleu::CamionBleu():Camion(50){
	instanceCamionBleu++;
}


CamionBleu::~CamionBleu(){
	instanceCamionBleu--;
}

bool CamionBleu::ajouterDechet(DechetTraiteRecyclabe* dechetTR) {
Camion:ajouterDechet(dechetTR);
	return true;
}