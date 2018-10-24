#pragma once
#include "MagBox.h"
class Memoire
{
public:
	Memoire();
	~Memoire();
	unsigned char registre;
	unsigned char state;
	unsigned char pCounter;
	unsigned char tabRam[32]; // tableau qui contiendra la ram actuel
	void memoire(unsigned char* );//fonction qui va prendre toute la "ram" du programme actuelle et la mettre dans son tableau
};

