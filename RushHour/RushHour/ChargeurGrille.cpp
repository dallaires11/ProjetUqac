#include "ChargeurGrille.h"

Grille* ChargeurGrille::chargerGrille()
{
	return chargerGrille(1, 1);
}

Grille* ChargeurGrille::chargerGrille(int niveau)
{
	return chargerGrille(niveau, 1);	// niveau par defaut
}

Grille* ChargeurGrille::chargerGrille(int niveau, int id)
{
	// pour le moment, on charge seulement le niveau 1, grille 1
	Grille* grille = new Grille(niveau, id);

	grille->ajouterVoiture(Position(0, 4), Position(2, 4));
	grille->ajouterVoiture(Position(2, 2), Position(2, 3));
	grille->ajouterVoiture(Position(3, 3), Position(4, 3));
	grille->ajouterVoiture(Position(4, 4), Position(4, 5));

	return grille;
}
