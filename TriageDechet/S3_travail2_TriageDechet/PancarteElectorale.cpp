#include "PancarteElectorale.h"

int PancarteElectorale::instancePancarte = 0;

PancarteElectorale::PancarteElectorale() :
	Dechet(24, "Votez Pierre Dosti - QS", 0, "Brun", 0, 50, false, false) {

	PancarteElectorale::instancePancarte++;
	//std::cout << "Creation: Pancarte\n";
}

PancarteElectorale::PancarteElectorale(const PancarteElectorale& pseudoPancarte) :Dechet(24, "Votez Pierre Dosti - QS", 0, "Brun", 0, 50, false, false) {
	PancarteElectorale::instancePancarte++;
	//std::cout << "Creation: Pancarte\n";
}

PancarteElectorale::~PancarteElectorale(){
	PancarteElectorale::instancePancarte--;
	//std::cout << "Desctruction: Pancarte\n";
}