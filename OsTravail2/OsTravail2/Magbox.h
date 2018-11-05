#pragma once
#define uChar unsigned char // Chortcut
#include <fstream>
using namespace std;
const int rSize = 32;  // Taille des registre
const int instruct = 2;//3 instructions avant de changer de fichier

class MagBox
{
	uChar *RAM;
	uChar Registre;
	uChar State;

public:
	MagBox();
	uChar PCounter; // Pointeur d'instruction, instruction suivante

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
	void run();
};
