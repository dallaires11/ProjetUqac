/*#include"Dechet.h"
#include"Devoir.h"
#include"Bureau.h"
#include"AssietteJetable.h"
#include"Bardeau.h"
#include"Bouffe.h"
#include"Bouteille.h"
#include"Canette.h"
#include"PancarteElectorale.h"
#include"Ustensile.h"
#include"ReveEleve.h"
#include"Plante.h"
#include"chargementDechet.h"
#include"UQAC.h"*/
#include"Compteur.h"

using namespace std;

int main() {
	Compteur c = Compteur();
	cout << endl<<"Il y a "<< c.getTotalInstance() <<" au total"<<endl<<endl;
	c.getAllInstance();

	system("PAUSE");
	return 0;
}