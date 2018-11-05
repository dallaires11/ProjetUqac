#include "AssietteJetable.h"

int AssietteJetable::instanceAssiette = 0;

AssietteJetable::AssietteJetable() :
	Dechet(3, "Assiette jetable", 0, "Blanc", 8, 1, true, false) {

	AssietteJetable::instanceAssiette++;
	//std::cout << "Creation: Assiette\n";
}

AssietteJetable::AssietteJetable(const AssietteJetable& pseudoAssiette) :Dechet(3, "Assiette jetable", 0, "Blanc", 8, 1, true, false) {
	AssietteJetable::instanceAssiette++;
	//std::cout << "Creation: Assiette\n";
}

AssietteJetable::~AssietteJetable(){
	AssietteJetable::instanceAssiette--;
	//std::cout << "Desctruction: Assiette\n";
}
