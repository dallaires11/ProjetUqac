#include "stdafx.h"
#include "Magbox.h"
#include <iostream>


MagBox::MagBox()
{
	RAM = new uChar[rSize * 2];
	Registre = 0;
	PCounter = 0;
	State = 'L';
}

void MagBox::run()
{
	int compteInstruc = 0;
	while (keepRunning())
	{
		if (compteInstruc > instruct)//si compteInstruc plus grand que 2 donc 3 tours avant de changer de programme
			break;
		else compteInstruc++; 
		char no = (RAM[PCounter] & 224) >> 5;
		uChar data = (RAM[PCounter] & 31);
		char adresseData = (RAM[PCounter] & 31) + 32;

		switch (no)
		{
		case 0: // CPY  valeur	: Copie valeur dans le registre.
			Registre = data;
			PCounter++;
			break;
		case 1: // RED [adresse]	: Copie le contenu d'adresse dans le registre.
			Registre = RAM[adresseData] & 31;
			PCounter++;
			break;
		case 2:                               // WRT [adresse]	: Copie le registre dans adresse.
			RAM[adresseData] = Registre & 31; // & 31 inutile en principe
			PCounter++;
			break;
		case 3: // ADD [adresse]	: Additionne la valeur dans adresse au registre.
			Registre += RAM[adresseData] & 31;
			PCounter++;
			break;
		case 4: // SUB  adresse	: Soustrait la valeur dans adresse au registre.
			Registre -= RAM[adresseData] & 31;
			PCounter++;
			break;
		case 5: // JMP  adresse	: Effectue un saut à l'adresse dans le registre et copie data dans le registre.
			PCounter = Registre;
			Registre = data;
			break;
		case 6: // JEQ  adresse	: Effectue un saut (jump) à adresse si la valeur du registre est égale à 0.
			if (Registre == 0)
				PCounter = data;
			else
				PCounter++;
			break;
		case 7:            // INT valeur	Effectue l'interruption data.
			if (data == 0) // écrire à l'écran
			{
				uChar adresseData = (Registre & 31) + 32;
				cout << (RAM[adresseData] != 0 ? (char)(59 + RAM[adresseData]) : ' ');
			}
			if (data == 1) // fin d'une exécution
				shutdown();
			PCounter++;
			break;
		}
	}
}



