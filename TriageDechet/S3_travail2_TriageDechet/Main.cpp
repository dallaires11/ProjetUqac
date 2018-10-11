#include"Dechet.h"
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
using namespace std;

int main() {
	Dechet* d = new Dechet();
	cout << *d << endl;
	Devoir* d2 = new Devoir();
	cout << *d2 << endl;
	Bureau* d3 = new Bureau();
	cout << *d3 << endl;
	AssietteJetable* d4 = new AssietteJetable();
	cout << *d4 << endl;
	Bardeau* d5 = new Bardeau();
	cout << *d5 << endl;
	Bouffe* d6 = new Bouffe();
	cout << *d6 << endl;
	Bouteille* d7 = new Bouteille(4);
	cout << *d7 << endl;
	Canette* d8 = new Canette();
	cout << *d8 << endl;
	PancarteElectorale* d9 = new PancarteElectorale();
	cout << *d9 << endl;
	Ustensile* d10 = new Ustensile();
	cout << *d10 << endl;
	ReveEleve* d11 = new ReveEleve();
	cout << *d11 << endl;
	Plante* d12 = new Plante();
	cout << *d12 << endl;
	

	cout<<"Nombre d'instance "<<Dechet::getNbInstance()<<endl;
	delete d;
	delete d2;
	delete d3;
	delete d4;
	delete d5;
	delete d6;
	delete d7;
	delete d8;
	delete d9;
	delete d10;
	delete d11;
	delete d12;
	cout << "Nombre d'instance " << Dechet::getNbInstance() << endl;

	system("PAUSE");
	return 0;
}