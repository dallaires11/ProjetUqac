#include "stdafx.h"
#include "Memoire.h"


Memoire::Memoire()
{
	registre = 0;
	state = 'L';
	pCounter = 0;

}


Memoire::~Memoire()
{
}

void Memoire::memoire(unsigned char* ram)
{
	for (int i = 0; i < 32; i++) {
		tabRam[i] = ram[i];
	}
}
