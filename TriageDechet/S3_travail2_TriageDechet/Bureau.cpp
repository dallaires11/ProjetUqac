#include "Bureau.h"

int Bureau::instanceBureau = 0;

Bureau::Bureau() :
	Dechet(65, "Grand bureau de merisier 10X45", 0, "Brun", 5, 80, false, true) {

	Bureau::instanceBureau++;
	//std::cout << "Creation: Bureau\n";
}

Bureau::Bureau(const Bureau& pseudoBureau) :Dechet(65, "Grand bureau de merisier 10X45", 0, "Brun", 5, 80, false, true) {
	Bureau::instanceBureau++;
	//std::cout << "Creation: Bureau\n";
}

Bureau::~Bureau(){
	Bureau::instanceBureau--;
	//std::cout << "Destruction: Bureau\n";
}
