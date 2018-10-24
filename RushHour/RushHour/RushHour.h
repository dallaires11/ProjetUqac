#ifndef RUSHHOUR_H
#define RUSHHOUR_H

#include "Grille.h"
#include "ChargeurGrille.h"

class RushHour
{
public:
	RushHour();
	~RushHour();

	void chargerGrille(int niveau, int id);
	void bougerVoiture(int x, int y, char deplacement);

private:
	Grille * grille;
};

#endif