#include <algorithm>
#include "Grille.h"

Grille::Grille(int niveau, int id)
{
	for (int x = 0; x < 6; x++)
		for (int y = 0; y < 6; y++)
			donnees[x][y] = NULL;
	voitureCourante = 0;
	nombreCoup = 0;
	this->niveau = niveau;
	this->id = id;
}

Grille::~Grille()
{
	// TODO : Validation ici
	for (int x = 0; x < 6; x++)
		for (int y = 0; y < 6; y++)
			if (donnees[x][y] != NULL)
				delete donnees[x][y];
}

void Grille::ajouterVoiture(const Position& depart, const Position& fin)
{
	Voiture* voiture;

	if (depart.getX() == fin.getX())		// horizontal
	{
		voiture = new Voiture(voitureCourante, true);

		int min = std::min(depart.getY(), fin.getY());
		int max = std::max(depart.getY(), fin.getY());
		for (int y = min; y <= max; y++)
			donnees[depart.getX()][y] = voiture;
	}
	else   // vertical
	{
		voiture = new Voiture(voitureCourante, false);
		int min = std::min(depart.getX(), fin.getX());
		int max = std::max(depart.getX(), fin.getX());
		for (int x = min; x <= max; x++)
			donnees[x][depart.getY()] = voiture;
	}
	voitureCourante++;
}

void Grille::bougerVoiture(int x, int y, char deplacement)
{
	/*
	if (donnees[x][y] == NULL)
		return;

		if (donnees[x][y]->estHorizontal())
	{
		if (deplacement == 'G')
			bougerGauche(x, y);
		else if (deplacement == 'D')
			bougerDroite(x, y);
	}
	else
	{
		if (deplacement == 'H')
			bougerHaut(x, y);
		else if (deplacement == 'B')
			bougerBas(x, y);
	}
	*/

}

void Grille::bougerGauche(int x, int y)
{

	/*
	int min = y;
	int max = y;
	Voiture* voitureCourante = donnees[x][y];

	while (donnees[x][min] == voitureCourante)	// Trouver la limite à gauche
	{
	if (min == 0)
	return;
	min--;
	}

	do {
	donnees[x][min] = donnees[x][min+1];
	min++;
	} while (donnees[x][min] == voitureCourante);

	nombreCoup++;

	*/
}

void Grille::bougerDroite(int x, int y)
{
	/*
	if (vehicule == 'A' && x0 == 2 && yMax == 5) {	// FINI!!!!!
	finPartie = true;
	nbMouvement++;
	}
	else if (yMax < (grille[0][0].length - 1))		// On est toujours dans le tableau
	if (grille[niveau][x0][yMax + 1] == VIDE) {	// Il n'y a pas de bateau a droite
	for (int y = yMax; y >= yMin; y--)	// Decalage
	grille[niveau][x0][y + 1] = grille[niveau][x0][y];
	grille[niveau][x0][yMin] = VIDE;
	nbMouvement++;
	}

	*/
}

void Grille::bougerHaut(int x, int y)
{
	/*
	if (xMin > 0)								// On est toujours dans le tableau
	if (grille[niveau][xMin - 1][y0] == VIDE) {	// Il n'y a pas de bateau en haut
	for (int x = xMin; x <= xMax; x++)	// Decalage
	grille[niveau][x - 1][y0] = grille[niveau][x][y0];
	grille[niveau][xMax][y0] = VIDE;
	nbMouvement++;
	}

	*/
}

void Grille::bougerBas(int x, int y)
{
	/*
	if (xMax < (grille[0][0].length - 1))		// On est toujours dans le tableau
	if (grille[niveau][xMax + 1][y0] == VIDE) {	// Il n'y a pas de bateau en bas
	for (int x = xMax; x >= xMin; x--)	// Decalage
	grille[niveau][x + 1][y0] = grille[niveau][x][y0];
	grille[niveau][xMin][y0] = VIDE;
	nbMouvement++;
	}

	*/
}
