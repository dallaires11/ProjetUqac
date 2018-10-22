#include "RushHour.h"
#include "ChargeurGrille.h"

RushHour::RushHour()
{
}


RushHour::~RushHour()
{
	delete grille;
}

void RushHour::chargerGrille(int niveau, int id)
{
	grille = ChargeurGrille::chargerGrille(niveau, id);
}

void RushHour::bougerVoiture(int x, int y, char deplacement)
{
	grille->bougerVoiture(x, y, deplacement);
}
