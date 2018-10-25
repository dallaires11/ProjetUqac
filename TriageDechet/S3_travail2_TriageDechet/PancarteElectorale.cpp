#include "PancarteElectorale.h"

int PancarteElectorale::instancePancarte = 0;

PancarteElectorale::PancarteElectorale() :
	Dechet(24, "Votez Pierre Dosti - QS", 0, "Brun", 0, 50, false, false) {

	PancarteElectorale::instancePancarte++;
	//std::cout << "Creation: Pancarte\n";
}

PancarteElectorale::PancarteElectorale(PancarteElectorale* pseudoPancarte) :Dechet(
	pseudoPancarte->getPoids(), pseudoPancarte->getDescription(), pseudoPancarte->getTypePlastique(),
	pseudoPancarte->getCouleur(), pseudoPancarte->getMateriel(), pseudoPancarte->getPurete(), pseudoPancarte->estEnStyromousse(),
	pseudoPancarte->estRigide()) {
	PancarteElectorale::instancePancarte++;
	//std::cout << "Creation: Pancarte\n";
}

PancarteElectorale::~PancarteElectorale(){
	PancarteElectorale::instancePancarte--;
	//std::cout << "Desctruction: Pancarte\n";
}