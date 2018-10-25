#include "Depot.h"

int Depot::instanceDepot = 0;

Depot::Depot(){
	totalDTC = 0;
	totalDTR = 0;
	totalDTNR = 0;
	instanceDepot++;
}

Depot::~Depot(){
	instanceDepot--;
}

CamionBrun* Depot::getCamionBrun(){
	return new CamionBrun();
}

CamionBleu* Depot::getCamionBleu() {
	return new CamionBleu();
}

CamionVert* Depot::getCamionVert() {
	return new CamionVert();
}

void Depot::depotDechetTraite(CamionBrun* camion) {
	totalDTC += camion->viderCamion();

	delete camion;
	return;
}

void Depot::depotDechetTraite(CamionBleu* camion) {
	totalDTR += camion->viderCamion();

	delete camion;
	return;
}

void Depot::depotDechetTraite(CamionVert* camion) {
	totalDTNR += camion->viderCamion();

	delete camion;
	return;
}

std::ostream& operator<<(std::ostream& output, const Depot& depot) {
	output << "------DEPOT------" << "\n";
	output << "TotalDT Recyclabe: " << depot.totalDTR<< "\n";
	output << "TotalDT Non Recyclabe: " << depot.totalDTNR << "\n";
	output << "TotalDt Compstable: " << depot.totalDTC << "\n";
	output << "-----------------" << "\n";
	return output;
}