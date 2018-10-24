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

std::ostream& operator<<(std::ostream& output, const Depot& depot) {
	output << "------DEPOT------" << "\n";
	output << "TotalDT Recyclabe: " << depot.totalDTR<< "\n";
	output << "TotalDT Non Recyclabe: " << depot.totalDTNR << "\n";
	output << "TotalDt Compstable: " << depot.totalDTC << "\n";
	output << "-----------------" << "\n";
	return output;
}