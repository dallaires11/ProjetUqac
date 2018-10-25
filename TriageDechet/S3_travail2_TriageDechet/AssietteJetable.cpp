#include "AssietteJetable.h"

int AssietteJetable::instanceAssiette = 0;

AssietteJetable::AssietteJetable() :
	Dechet(3, "Assiette jetable", 0, "Blanc", 8, 1, true, false) {

	AssietteJetable::instanceAssiette++;
	//std::cout << "Creation: Assiette\n";
}

AssietteJetable::AssietteJetable(AssietteJetable* pseudoAssiette) :Dechet(
	pseudoAssiette->getPoids(), pseudoAssiette->getDescription(), pseudoAssiette->getTypePlastique(),
	pseudoAssiette->getCouleur(), pseudoAssiette->getMateriel(), pseudoAssiette->getPurete(), pseudoAssiette->estEnStyromousse(),
	pseudoAssiette->estRigide()) {
	AssietteJetable::instanceAssiette++;
	//std::cout << "Creation: Assiette\n";
}

AssietteJetable::~AssietteJetable(){
	AssietteJetable::instanceAssiette--;
	//std::cout << "Desctruction: Assiette\n";
}
