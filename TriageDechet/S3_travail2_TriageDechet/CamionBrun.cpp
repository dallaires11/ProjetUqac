#include "CamionBrun.h"

int CamionBrun::instanceCamionBrun = 0;

CamionBrun::CamionBrun():Camion(30){
	instanceCamionBrun++;
}

CamionBrun::CamionBrun(const CamionBrun& pseudoBrun):Camion(50) {
	instanceCamionBrun++;
}

CamionBrun::~CamionBrun(){
	instanceCamionBrun--;
}

bool CamionBrun::ajouterDechet(DechetTraiteCompostable* dechetTC) {
	return Camion::ajouterDechet(dechetTC);
}