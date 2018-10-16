#pragma once
#include"Dechet.h"
#include"PancarteElectorale.h"
#include"Bouteille.h"
#include"Ustensile.h"
#include"Canette.h"
#include"Plante.h"
#include"Bureau.h"
#include"Bouffe.h"
#include"Devoir.h"
#include"AssietteJetable.h"
#include"Bardeau.h"
#include"ReveEleve.h"
class chargementDechet{
private:
	int current;
	Dechet* listeDechet[11];//50];
	void setDechet();
public:
	chargementDechet();
	Dechet* getDechet();
	~chargementDechet();
};

