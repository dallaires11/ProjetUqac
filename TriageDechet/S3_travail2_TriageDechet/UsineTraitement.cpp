#include "UsineTraitement.h"

int UsineTraitement::instanceUsine = 0;

UsineTraitement::UsineTraitement(){
	depot = Depot();
	camionBleu = depot.getCamionBleu();
	camionBrun = depot.getCamionBrun();
	camionVert = depot.getCamionVert();
	sequenceOperation = NULL;
	instanceUsine++;
}

UsineTraitement::UsineTraitement(const UsineTraitement& pseudoUsine) {
	depot = pseudoUsine.depot;
	camionBleu = pseudoUsine.camionBleu;
	camionBrun = pseudoUsine.camionBrun;
	camionVert = pseudoUsine.camionVert;
	sequenceOperation = pseudoUsine.sequenceOperation;
	instanceUsine++;
}

UsineTraitement::~UsineTraitement(){
	depot.depotDechetTraite(camionBrun);
	depot.depotDechetTraite(camionBleu);
	depot.depotDechetTraite(camionVert);
	delete sequenceOperation;
	instanceUsine--;

	Log::i(depot);
}

void UsineTraitement::traiterDTC(Dechet* dechet) {
	Log::i("AJOUT DTC  : " + std::to_string(dechet->getId()));
	
	DechetTraiteCompostable* dechetC = new DechetTraiteCompostable(dechet);
	if(camionBrun->ajouterDechet(dechetC))
		return;
	else {
		depot.depotDechetTraite(camionBrun);
		camionBrun = depot.getCamionBrun();
		camionBrun->ajouterDechet(dechetC);
		return;
	}
}

void UsineTraitement::traiterDTR(Dechet* dechet) {
	Log::i("AJOUT DTR  : " + std::to_string(dechet->getId()));

	DechetTraiteRecyclabe* dechetR= new DechetTraiteRecyclabe(dechet);
	if (camionBleu->ajouterDechet(dechetR))
		return;
	else {
		depot.depotDechetTraite(camionBleu);
		camionBleu = depot.getCamionBleu();
		camionBleu->ajouterDechet(dechetR);
		return;
	}
}

void UsineTraitement::traiterDTNR(Dechet* dechet) {
	Log::i("AJOUT DTNR  : " + std::to_string(dechet->getId()));

	DechetTraiteNonRecyclabe* dechetNR = new DechetTraiteNonRecyclabe(dechet);
	if (camionVert->ajouterDechet(dechetNR))
		return;
	else {
		depot.depotDechetTraite(camionVert);
		camionVert = depot.getCamionVert();
		camionVert->ajouterDechet(dechetNR);
		return;
	}
}

void UsineTraitement::chargerOperation(SequenceOperation* seqOp) {
	Log::i("CHARGEMENT DES OPERATIONS");

	sequenceOperation = seqOp;
	return;
}

void UsineTraitement::demmarerTraitement(ChargementDechet* chargement) {
	Log::i("DEMARRAGE DES OPERATIONS");

	Operation* currentOperation = sequenceOperation->getOperation();
	Dechet* currentDechet = chargement->getDechet();
	
	while (currentDechet != NULL) {
		Log::i(*currentDechet);

		preOperation();
		while (currentOperation != NULL) {
			currentOperation = currentOperation->getOperationSuivante(currentOperation->effectuerOperation(currentDechet));
		}
		postOperation();

		currentOperation = sequenceOperation->getOperation();
		currentDechet = chargement->getDechet();
	}
	Log::i(depot);

	return;
}