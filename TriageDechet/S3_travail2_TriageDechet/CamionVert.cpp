#include "CamionVert.h"

int CamionVert::instanceCamionVert = 0;

CamionVert::CamionVert() : Camion(70){
	instanceCamionVert++;
}


CamionVert::~CamionVert(){
	instanceCamionVert--;
}

bool CamionVert::ajouterDechet(DechetTraiteNonRecyclabe* dechetTNR) {
	return Camion::ajouterDechet(dechetTNR);

}