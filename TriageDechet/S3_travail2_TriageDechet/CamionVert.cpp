#include "CamionVert.h"

int CamionVert::instanceCamionVert = 0;

CamionVert::CamionVert() : Camion(70){
	instanceCamionVert++;
}


CamionVert::~CamionVert(){
	instanceCamionVert--;
}

bool CamionVert::ajouterDechet(DechetTraiteNonRecyclabe* dechetTNR) {
Camion:ajouterDechet(dechetTNR);
	return true;
}