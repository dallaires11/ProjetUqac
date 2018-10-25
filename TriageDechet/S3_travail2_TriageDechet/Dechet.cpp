#include "Dechet.h"

int Dechet::dechetCurrentId = 0;
int Dechet::instanceDechet = 0;

Dechet::Dechet(){
	id = Dechet::dechetCurrentId++;
	poids = 25;
	description = "Packet suspect produisant d'etrange bruit a interval regulier";
	setTypePlastique(0);
	couleur = "inconnu";
	typeMateriel = Inconnu;
	setPurete(100);
	styromousse = false;
	rigide = true;
	Dechet::instanceDechet++;
	//std::cout << "Creation: Dechet\n";
}

Dechet::Dechet(int iPoids, std::string iDescription, int iTypePlastique, std::string iCouleur, int iMateriel, int iPurete, bool iStyromousse, bool iRigide) {
	id = Dechet::dechetCurrentId++;
	setPoids(iPoids);
	setDescription(iDescription);
	setTypePlastique(iTypePlastique);
	setCouleur(iCouleur);
	typeMateriel = (Materiel)iMateriel;
	setPurete(iPurete);
	styromousse = iStyromousse;
	rigide = iRigide;
	Dechet::instanceDechet++;
	//std::cout << "Creation: Dechet\n";
}

Dechet::Dechet(int iPoids, std::string iDescription) {
	id = Dechet::dechetCurrentId++;
	setPoids(iPoids);
	setDescription(iDescription);
	setTypePlastique(0);
	couleur = "inconnu";
	typeMateriel = Inconnu;
	setPurete(100);
	styromousse = false;
	rigide = true;
	Dechet::instanceDechet++;
	//std::cout << "Creation: Dechet\n";
}

Dechet::Dechet(Dechet* pseudoDechet) {
	id = Dechet::dechetCurrentId++;
	setPoids(pseudoDechet->getPoids());
	setDescription(pseudoDechet->getDescription());
	setTypePlastique(pseudoDechet->getTypePlastique());
	setCouleur(pseudoDechet->getCouleur());
	typeMateriel = pseudoDechet->getMateriel();
	setPurete(pseudoDechet->getPurete());
	styromousse = pseudoDechet->estEnStyromousse();
	rigide = pseudoDechet->estRigide();
	Dechet::instanceDechet++;
	//std::cout << "Creation: Dechet\n";
}

Dechet::~Dechet(){
	Dechet::instanceDechet--;
	//std::cout << "Destruction: Dechet\n";
}

void Dechet::setPoids(int iPoids) {
	if (iPoids < 0)
		poids = 0;
	else if (iPoids > 100)
		poids = 100;
	else
		poids = iPoids;
	return;
}

void Dechet::setDescription(std::string iDescrip) {
	if (iDescrip.length() < 3)
		description = '???';
	else
		description = iDescrip;
	return;
}

void Dechet::setTypePlastique(int iPlastique) {
	if ((iPlastique < 1) | (iPlastique>7))
		typePlatique = 0;
	else
		typePlatique = iPlastique;
	return;
}

void Dechet::setCouleur(std::string iCouleur){
	if ((iCouleur.compare("brun") != 1) | (iCouleur.compare("vert") != 1))
		couleur = "inconnu";
	else
		couleur = iCouleur;
	return;
}

void Dechet::setPurete(int iPurete) {
	if (iPurete < 1)
		purete = 1;
	else if (iPurete > 100)
		purete = 100;
	else
		purete = iPurete;
	return;
}

std::ostream& operator<<(std::ostream& output, const Dechet& dechet) {
	output << "------------------------------" << "\n";
	output << "Id		:" << dechet.id << "\n";
	output << "Poids		:" << dechet.poids << "\n";
	output << "Description	:" << dechet.description << "\n";
	output << "Type		:" << dechet.typePlatique << "\n";
	output << "Couleur		:" << dechet.couleur << "\n";
	output << "Materiel	:" << dechet.typeMateriel << "\n";
	output << "Purete		:" << dechet.purete << "\n";
	output << "Styromousse	:" << dechet.styromousse << "\n";
	output << "Rigide		:" << dechet.rigide << "\n";
	output << "------------------------------" << "\n";
	return output;
}