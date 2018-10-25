#pragma once
#include"UQAC.h"
#include"UsineTraitement.h"
#include"GenerateurSeqOperation.h"
class Compteur{
public:
	Compteur();
	~Compteur();

	void getAllInstance(bool);
	int getTotalInstance(bool);
};