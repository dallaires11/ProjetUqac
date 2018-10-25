#include"Compteur.h"

using namespace std;

void laboratoire2();
void afficherInfo();

int main() {
	laboratoire2();
	afficherInfo();

	system("PAUSE");
	return 0;
}

void laboratoire2() {
	ChargementDechet* chargement = UQAC::getChargementDechets();
	UsineTraitement* usineTraitement = new UsineTraitement();
	GenerateurSeqOperation genSeq;

	//usineTraitement->chargerOperation(genSeq.genererSequence(0,usineTraitement));
	//usineTraitement->demmarerTraitement(chargement);

	delete usineTraitement;
	return;
}

void afficherInfo() {
	Compteur c = Compteur();
	cout << endl << "Il y a " << c.getTotalInstance() << " au total" << endl << endl;
	c.getAllInstance();
	return;
}