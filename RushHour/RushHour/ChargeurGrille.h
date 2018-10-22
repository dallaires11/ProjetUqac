#ifndef CHARGEURGRILLE_H
#define CHARGEURGRILLE_H

#include "Grille.h"

class ChargeurGrille
{
private:
	ChargeurGrille() {};
public:
	~ChargeurGrille() {};
	static Grille* chargerGrille();
	static Grille* chargerGrille(int niveau);
	static Grille* chargerGrille(int niveau, int id);
};

#endif