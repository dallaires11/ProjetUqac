#include "ReveEleve.h"

int ReveEleve::instanceReve = 0;

ReveEleve::ReveEleve() :
	Dechet(0, "L'espoir d'un etudian d'avoir une bonne note dans l'examen", 0, "Incolore", 0, 100, false, false) {

	ReveEleve::instanceReve++;
	//std::cout << "Creation: Reve\n";
}

ReveEleve::ReveEleve(const ReveEleve& pseudoReve) :Dechet(0, "L'espoir d'un etudian d'avoir une bonne note dans l'examen", 0, "Incolore", 0, 100, false, false) {
	ReveEleve::instanceReve++;
	//std::cout << "Creation: Reve\n";
}

ReveEleve::~ReveEleve(){
	ReveEleve::instanceReve--;
	//std::cout << "Desctruction: Reve\n";
}
