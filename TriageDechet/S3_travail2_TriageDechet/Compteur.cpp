#include "Compteur.h"

Compteur::Compteur() {}

Compteur::~Compteur()
{}

void Compteur::getAllInstance() {
	std::cout << "Instance ChargementDechet: " << ChargementDechet::getNbInstance() << std::endl;
	std::cout << "Instance UQAC: " << UQAC::getNbInstance()<<std::endl;
	std::cout << "Instance UsineTraitement: " << UsineTraitement::getNbInstance() << std::endl;
	std::cout << "Instance GenerateurSeqOperation: " << GenerateurSeqOperation::getNbInstance() << std::endl;
	/*std::cout << "Instance Camion: " << Camion::getNbInstance() << std::endl;
	std::cout << "Instance CamionBleu: " << CamionBleu::getNbInstance() << std::endl;
	std::cout << "Instance CamionBrun: " << CamionBrun::getNbInstance() << std::endl;
	std::cout << "Instance CamionVert: " << CamionVert::getNbInstance() << std::endl;
	std::cout << "Instance Dechet: " << Dechet::getNbInstance() << std::endl;
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
	std::cout << "Instance DechetTraite: " << DechetTraite::getNbInstance() << std::endl;
	std::cout << "Instance DechetTraiteComspostable: " << DechetTraiteCompostable::getNbInstance() << std::endl;
	std::cout << "Instance DechetTraiteRecyclabe: " << DechetTraiteRecyclabe::getNbInstance() << std::endl;
	std::cout << "Instance DechetTraiteNonRecyclabe: " << DechetTraiteNonRecyclabe::getNbInstance() << std::endl;
	std::cout << "Instance UQAC: " << Operation::getNbInstance() << std::endl;
	std::cout << "Instance UQAC: " << Operation1::getNbInstance() << std::endl;
	std::cout << "Instance UQAC: " << Operation2::getNbInstance() << std::endl;
	std::cout << "Instance UQAC: " << Operation3::getNbInstance() << std::endl;
	std::cout << "Instance UQAC: " << Operation4::getNbInstance() << std::endl;
	std::cout << "Instance UQAC: " << Operation5::getNbInstance() << std::endl;
	std::cout << "Instance UQAC: " << Operation6::getNbInstance() << std::endl;
	std::cout << "Instance UQAC: " << OperationTraitement::getNbInstance() << std::endl;
	std::cout << "Instance UQAC: " << CreationDTC::getNbInstance() << std::endl;
	std::cout << "Instance UQAC: " << CreationDTNR::getNbInstance() << std::endl;
	std::cout << "Instance UQAC: " << CreationDTR::getNbInstance() << std::endl;
	std::cout << "Instance UQAC: " << SequenceOperation::getNbInstance() << std::endl;
	std::cout << "Instance UQAC: " << GenerateurSeqOperation::getNbInstance() << std::endl;
	std::cout << "Instance UQAC: " << Depot::getNbInstance() << std::endl;*/
	return;
}

int Compteur::getTotalInstance() {
	int total = 0;
	total += ChargementDechet::getNbInstance();
	total += UQAC::getNbInstance();
	total += UsineTraitement::getNbInstance();
	total += GenerateurSeqOperation::getNbInstance();
	/*std::cout << "Instance UQAC: " << UQAC::getNbInstance()<<std::endl;
	std::cout << "Instance UsineTraitement: " << UsineTraitement::getNbInstance() << std::endl;
	std::cout << "Instance Camion: " << Camion::getNbInstance() << std::endl;
	std::cout << "Instance CamionBleu: " << CamionBleu::getNbInstance() << std::endl;
	std::cout << "Instance CamionBrun: " << CamionBrun::getNbInstance() << std::endl;
	std::cout << "Instance CamionVert: " << CamionVert::getNbInstance() << std::endl;
	std::cout << "Instance ChargementDechet: " << chargementDechet::getNbInstance() << std::endl;
	std::cout << "Instance Dechet: " << Dechet::getNbInstance() << std::endl;
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
	std::cout << "Instance DechetTraite: " << DechetTraite::getNbInstance() << std::endl;
	std::cout << "Instance DechetTraiteComspostable: " << DechetTraiteCompostable::getNbInstance() << std::endl;
	std::cout << "Instance DechetTraiteRecyclabe: " << DechetTraiteRecyclabe::getNbInstance() << std::endl;
	std::cout << "Instance DechetTraiteNonRecyclabe: " << DechetTraiteNonRecyclabe::getNbInstance() << std::endl;
	std::cout << "Instance UQAC: " << Operation::getNbInstance() << std::endl;
	std::cout << "Instance UQAC: " << Operation1::getNbInstance() << std::endl;
	std::cout << "Instance UQAC: " << Operation2::getNbInstance() << std::endl;
	std::cout << "Instance UQAC: " << Operation3::getNbInstance() << std::endl;
	std::cout << "Instance UQAC: " << Operation4::getNbInstance() << std::endl;
	std::cout << "Instance UQAC: " << Operation5::getNbInstance() << std::endl;
	std::cout << "Instance UQAC: " << Operation6::getNbInstance() << std::endl;
	std::cout << "Instance UQAC: " << OperationTraitement::getNbInstance() << std::endl;
	std::cout << "Instance UQAC: " << CreationDTC::getNbInstance() << std::endl;
	std::cout << "Instance UQAC: " << CreationDTNR::getNbInstance() << std::endl;
	std::cout << "Instance UQAC: " << CreationDTR::getNbInstance() << std::endl;
	std::cout << "Instance UQAC: " << SequenceOperation::getNbInstance() << std::endl;
	std::cout << "Instance UQAC: " << GenerateurSeqOperation::getNbInstance() << std::endl;
	std::cout << "Instance UQAC: " << Depot::getNbInstance() << std::endl;*/
	return total;
}