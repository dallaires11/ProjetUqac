#pragma once
#include<string>
#include<iostream>
#include<ostream>
class Dechet{
private:
	static int dechetCurrentId;
	static int instanceDechet;
	
	int id;
	int poids;
	std::string description;
	int typePlatique;
	std::string couleur;
	enum Materiel {Carton,Bouteille,Plastique,Metal,Vegetal,Bois,Nourriture,Papier,Styromousse,Inconnu};
	Materiel typeMateriel;
	int purete;
	bool styromousse;
	bool rigide;

	void setPoids(int);
	void setDescription(std::string);
	void setTypePlastique(int);
	void setCouleur(std::string);
	void setPurete(int);
protected:
	Dechet(int iPoids, std::string iDescription, int iTypePlastique, std::string iCouleur, int iMateriel, int iPurete, bool iStyromousse, bool iRigide);
	Dechet(int iPoids, std::string iDescription);
public:
	Dechet();
	Dechet(const Dechet&);
	virtual ~Dechet();

	const int getPoids() {
		return poids;
	}
	const int getId() {
		return id;
	}
	const std::string getDescription() {
		return description;
	}
	const int getTypePlastique() {
		return typePlatique;
	}
	const std::string getCouleur() {
		return couleur;
	}
	const Materiel getMateriel() {
		return typeMateriel;
	}
	const int getPurete() {
		return purete;
	}
	const bool estEnStyromousse() {
		return styromousse;
	}
	const bool estRigide() {
		return rigide;
	}
	
	static const int getNbInstance() {
		return Dechet::instanceDechet;
	}

	friend std::ostream& operator<<(std::ostream& out, const Dechet& dechet);
};

