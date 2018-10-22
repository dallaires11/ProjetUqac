#ifndef GRILLE_H
#define GRILLE_H

#include "Position.h"

class Grille
{
public:
	Grille(int niveau, int id);
	~Grille();
	int getNiveau() const { return niveau; }
	int getId() const { return id; }
	void ajouterVoiture(const Position& depart, const Position& fin);
	void bougerVoiture(int x, int y, char deplacement);

private:
	class Voiture{
		public:
			Voiture(int id, bool horizontal) :id(id), horizontal(horizontal) {};
			~Voiture() {};
			bool estHorizontal() const { return horizontal; }
			int getId() const { return id; }
		private:
			int id;
			bool horizontal;
	};
	Voiture* donnees[6][6];
	int voitureCourante;
	int niveau;
	int id;
	int nombreCoup;

	void bougerGauche(int x, int y);
	void bougerDroite(int x, int y);
	void bougerHaut(int x, int y);
	void bougerBas(int x, int y);
};

#endif
