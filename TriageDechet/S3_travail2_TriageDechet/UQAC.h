#pragma once
#include"chargementDechet.h"
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

class UQAC{
private:
	static int instanceUqac;
public:
	UQAC();
	~UQAC();

	static const int getNbInstance() {
		return UQAC::instanceUqac;
	}

	chargementDechet* getChargementDechets();
};