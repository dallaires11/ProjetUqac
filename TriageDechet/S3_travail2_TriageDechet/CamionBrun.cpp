#include "CamionBrun.h"

int CamionBrun::instanceCamionBrun = 0;

CamionBrun::CamionBrun():Camion(30){
	instanceCamionBrun++;
}


CamionBrun::~CamionBrun(){
	instanceCamionBrun--;
}

bool CamionBrun::ajouterDechet(DechetTraiteCompostable* dechetTC) {
	Camion:ajouterDechet(dechetTC);
}