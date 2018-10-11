#include <cstdlib>
#include <iostream>
#include <fstream>

#define uChar unsigned char // Chortcut
const int rSize = 32;       // Taille des registre

using namespace std;

class MagBox
{
	uChar *RAM;
	uChar Registre;
	uChar PCounter; // Pointeur d'instruction, instruction suivante
	uChar State;

public:
	MagBox()
	{
		RAM = new uChar[rSize * 2];
		Registre = 0;
		PCounter = 0;
		State = 'L';
	}

	~MagBox() { delete RAM; }
	uChar getPCounter() { return PCounter; }
	uChar getRegistre() { return Registre; }
	uChar getState() { return State; }
	void setPCounter(uChar PCounter) { PCounter = PCounter; }
	void setRegistre(uChar registre) { Registre = registre; }
	void setState(uChar state) { State = state; }

	void putRAM(uChar indice, uChar val) { RAM[indice] = val; }
	uChar getRAM(uChar indice) { return RAM[indice]; }

	bool keepRunning() { return State == 'L'; }
	void shutdown() { State = 'D'; }

	void run()
	{
		while (keepRunning())
		{
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
};

void loadProgram(char *fileName, MagBox &machine)
{
	ifstream file(fileName);
	if (!file.is_open())
	{
		cout << "File not found : " << fileName << endl;
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

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		cout << "oszero <nomDufichier.prg>" << endl;
		exit(-1);
	}
	MagBox machine;
	loadProgram(argv[1], machine);
	machine.run();

	cout << "\nPress a key to continue ...";
	getchar(); // Pour que la fenêtre reste à la fin d'une exécution
	return 0;
}