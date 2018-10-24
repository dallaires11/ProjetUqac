#include "stdafx.h"
#include "OuvreFichier.h"


OuvreFichier::OuvreFichier()
{
}


OuvreFichier::~OuvreFichier()
{
}

bool OuvreFichier::testPresent(string fichier)
{
	ifstream file(fichier);
	if (!file.is_open())
		return false;
	else
		return true;

}
