#include "Compteur.h"

Compteur::Compteur() {}

Compteur::~Compteur()
{}

void Compteur::getAllInstance(bool debug) {
	std::cout << "Instance ChargementDechet: " << ChargementDechet::getNbInstance() << std::endl;
	std::cout << "Instance UQAC: " << UQAC::getNbInstance()<<std::endl;
	std::cout << "Instance UsineTraitement: " << UsineTraitement::getNbInstance() << std::endl;
	std::cout << "Instance GenerateurSeqOperation: " << GenerateurSeqOperation::getNbInstance() << std::endl;
	std::cout << "Instance Camion: " << Camion::getNbInstance() << std::endl;
	if (debug) {
		std::cout << "Instance CamionBleu: " << CamionBleu::getNbInstance() << std::endl;
		std::cout << "Instance CamionBrun: " << CamionBrun::getNbInstance() << std::endl;
		std::cout << "Instance CamionVert: " << CamionVert::getNbInstance() << std::endl;
	}
	std::cout << "Instance Dechet: " << Dechet::getNbInstance() << std::endl;
	if (debug) {
		std::cout << "Instance AssietteJetable: " << AssietteJetable::getNbInstance() << std::endl;
		std::cout << "Instance Bardeau: " << Bardeau::getNbInstance() << std::endl;
		std::cout << "Instance Bouffe: " << Bouffe::getNbInstance() << std::endl;
		std::cout << "Instance Bouteille: " << Bouteille::getNbInstance() << std::endl;
		std::cout << "Instance Bureau: " << Bureau::getNbInstance() << std::endl;
		std::cout << "Instance Canette: " << Canette::getNbInstance() << std::endl;
		std::cout << "Instance Devoir: " << Devoir::getNbInstance() << std::endl;
		std::cout << "Instance PancarteElectorale: " << PancarteElectorale::getNbInstance() << std::endl;
		std::cout << "Instance Plante: " << Plante::getNbInstance() << std::endl;
		std::cout << "Instance ReveEleve: " << ReveEleve::getNbInstance() << std::endl;
		std::cout << "Instance Ustensile: " << Ustensile::getNbInstance() << std::endl;
	}
	
	std::cout << "Instance DechetTraite: " << DechetTraite::getNbInstance() << std::endl;
	if (debug) {
		std::cout << "Instance DechetTraiteComspostable: " << DechetTraiteCompostable::getNbInstance() << std::endl;
		std::cout << "Instance DechetTraiteRecyclabe: " << DechetTraiteRecyclabe::getNbInstance() << std::endl;
		std::cout << "Instance DechetTraiteNonRecyclabe: " << DechetTraiteNonRecyclabe::getNbInstance() << std::endl;
	}

	std::cout << "Instance Operation: " << Operation::getNbInstance() << std::endl;
	if (debug) {
		std::cout << "Instance Operation1: " << Operation1::getNbInstance() << std::endl;
		std::cout << "Instance Operation2: " << Operation2::getNbInstance() << std::endl;
		std::cout << "Instance Operation3: " << Operation3::getNbInstance() << std::endl;
		std::cout << "Instance Operation4: " << Operation4::getNbInstance() << std::endl;
		std::cout << "Instance Operation5: " << Operation5::getNbInstance() << std::endl;
		std::cout << "Instance Operation6: " << Operation6::getNbInstance() << std::endl;
		std::cout << "Instance OperationTraitement: " << OperationTraitement::getNbInstance() << std::endl;
		std::cout << "Instance CreationDTC: " << CreationDTC::getNbInstance() << std::endl;
		std::cout << "Instance CreationDTNR: " << CreationDTNR::getNbInstance() << std::endl;
		std::cout << "Instance CreationDTR: " << CreationDTR::getNbInstance() << std::endl;
	}

	std::cout << "Instance SequenceOperation: " << SequenceOperation::getNbInstance() << std::endl;
	std::cout << "Instance Depot: " << Depot::getNbInstance() << std::endl;

	return;
}

int Compteur::getTotalInstance(bool debug) {
	int total = 0;
	total += ChargementDechet::getNbInstance();
	total += UQAC::getNbInstance();
	total += UsineTraitement::getNbInstance();
	total += GenerateurSeqOperation::getNbInstance();
	total += Camion::getNbInstance();
	if (debug) {
		total += CamionBleu::getNbInstance();
		total += CamionBrun::getNbInstance();
		total += CamionVert::getNbInstance();
	}
	
	total += Dechet::getNbInstance();
	if (debug) {
		total += AssietteJetable::getNbInstance();
		total += Bardeau::getNbInstance();
		total += Bouffe::getNbInstance();
		total += Bouteille::getNbInstance();
		total += Bureau::getNbInstance();
		total += Canette::getNbInstance();
		total += Devoir::getNbInstance();
		total += PancarteElectorale::getNbInstance();
		total += Plante::getNbInstance();
		total += ReveEleve::getNbInstance();
		total += Ustensile::getNbInstance();
	}
	total += DechetTraite::getNbInstance();
	if (debug) {
		total += DechetTraiteCompostable::getNbInstance();
		total += DechetTraiteRecyclabe::getNbInstance();
		total += DechetTraiteNonRecyclabe::getNbInstance();
	}
	
	total += Operation::getNbInstance();
	if (debug) {
		total += Operation1::getNbInstance();
		total += Operation2::getNbInstance();
		total += Operation3::getNbInstance();
		total += Operation4::getNbInstance();
		total += Operation5::getNbInstance();
		total += Operation6::getNbInstance();
		total += OperationTraitement::getNbInstance();
		total += CreationDTC::getNbInstance();
		total += CreationDTNR::getNbInstance();
		total += CreationDTR::getNbInstance();
	}
	total += SequenceOperation::getNbInstance();
	total += Depot::getNbInstance();

	return total;
}