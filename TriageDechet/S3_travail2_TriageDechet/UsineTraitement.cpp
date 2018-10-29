#include "UsineTraitement.h"

int UsineTraitement::instanceUsine = 0;

UsineTraitement::UsineTraitement(){
	depot = Depot();
	camionBleu = new CamionBleu();
	camionBrun = new CamionBrun();
	camionVert = new CamionVert();
	sequenceOperation = NULL;
	instanceUsine++;
}


UsineTraitement::~UsineTraitement(){
	depot.depotDechetTraite(camionBrun);
	depot.depotDechetTraite(camionBleu);
	depot.depotDechetTraite(camionVert);
	//sequenceOperation->destroyOperations();
	delete sequenceOperation;
	instanceUsine--;
}

void UsineTraitement::traiterDTC(Dechet* dechet) {
	if(true/*camionBrun->ajouterDechet(dechet)*/)
		return;
	else {
		depot.depotDechetTraite(camionBrun);
		camionBrun = depot.getCamionBrun();
		traiterDTC(dechet);
		return;
	}
}

void UsineTraitement::traiterDTR(Dechet* dechet) {
	if (true)//camionBleu->ajouterDechet(dechet))
		return;
	else {
		depot.depotDechetTraite(camionBleu);
		camionBleu = depot.getCamionBleu();
		traiterDTR(dechet);
		return;
	}
}

void UsineTraitement::traiterDTNR(Dechet* dechet) {
	if (true/*camionVert->ajouterDechet(dechet)*/)
		return;
	else {
		depot.depotDechetTraite(camionVert);
		camionVert = depot.getCamionVert();
		traiterDTNR(dechet);
		return;
	}
}

void UsineTraitement::chargerOperation(SequenceOperation* seqOp) {
	sequenceOperation = seqOp;
	return;
}

void UsineTraitement::demmarerTraitement(ChargementDechet* chargement) {

}