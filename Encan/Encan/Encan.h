#pragma once
#include"enchere.h"
class Encan{
private:
	static Encan* instance;

	Encan();

public:
	static Encan* getInstance();
	enchere* encheresArt;
	int tailleEnchereArt;
	enchere* encheresAntique;
	int tailleEnchereAntique;
	enchere* encheresService;
	int tailleEnchereService;

	void fermeture();
};