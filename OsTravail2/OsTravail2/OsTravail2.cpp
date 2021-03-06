// OsTravail2.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <cstdlib>
#include"Magbox.h"
#include <iostream>
#include <string>
#include <fstream>
#include "OuvreFichier.h"
#include "Memoire.h"
using namespace std;

void loadProgram(string fichier, MagBox &machine);


int main(int argc, char *argv[])
{
	ofstream erase("rapport.txt", ios::out | ios::trunc);
	erase <<"" ;
	const int nbTour = 5;
	const int sautCode = 32;
	OuvreFichier test;
	bool testFichier;
	string fichier = "";
	string tabFichier[nbTour];
	cout << "Veuillez entrer vos 5 fichiers ici" << endl;

	for (int i = 0; i < nbTour; i++) 
	
	{
		cin >> fichier;
		testFichier = test.testPresent(fichier);
		if (testFichier == false) {
			i--;
			cout << "fichier non trouve"<<endl<<"entrez un nouveau nom de fichier"<<endl;

		}
		else {
			tabFichier[i] = fichier;
			cout << "felicitation le fichier est present" << endl;
		}
	}
		
	Memoire *tabMemoire[nbTour];
	for (int i = 0; i < nbTour; i++) {
		tabMemoire[i] = new Memoire();
	}
	MagBox *machine = new MagBox();
	ofstream rapport("rapport.txt", ios::out | ios::app);
	while (tabMemoire[0]->state!='D'||tabMemoire[1]->state != 'D' ||tabMemoire[2]->state != 'D' ||tabMemoire[3]->state != 'D' ||tabMemoire[4]->state != 'D' )
	//for (int i = 0; i < 2; i++)
	{
		for (int i = 0; i < nbTour; i++) {

			if (tabMemoire[i]->state != 'D') {

				loadProgram(tabFichier[i], *machine);
				machine->PCounter = tabMemoire[i]->pCounter;//je n'utilise pas le get parcequ'il ne fonctionnais pas
				//j'Ai donc mis le Pcounter de lobjet magbox public et j' accede dirrectement
				if (rapport) {//fichier qui met chaque instruction dans lordre qu'elles ont été fait dans le fichier rapport
					unsigned char p = machine->PCounter;
					int p1 = p;
					int p2 = 0;
					for (int i = 0; i < 3; i++) {
						p2 = machine->getRAM(p1);
						rapport << p2 << endl;
						p1++;
						if (p1 >= 32)
							break;
					}
				}
				machine->setState(tabMemoire[i]->state);
				machine->setRegistre(tabMemoire[i]->registre);
				for (int x = 0; x < sautCode; x++)
					machine->putRAM(x + sautCode, tabMemoire[i]->tabRam[x]);
		
				
				machine->run();
				tabMemoire[i]->pCounter = machine->getPCounter();
				tabMemoire[i]->registre = machine->getRegistre();
				tabMemoire[i]->state = machine->getState();
				for (int x = 0; x < sautCode; x++)
					tabMemoire[i]->tabRam[x] = machine->getRAM(x + sautCode);
			}
		}
	}

	cout << "\nPress a key to continue ...";
	getchar(); // Pour que la fenÃªtre reste Ã  la fin d'une exÃ©cution
	return 0;
}


void loadProgram(string fichier, MagBox &machine)
{
	ifstream file(fichier);
	if (!file.is_open())
	{
		cout << "File not found : " << fichier << endl;
		exit(EXIT_FAILURE);
	}
	int indice = 0;
	for (int x = 0; x < 64 && !file.eof(); x++)
	{
		int tamp = 0;
		file >> tamp;
		machine.putRAM(indice, (uChar)tamp);
		indice++;
	}
	file.close();
}