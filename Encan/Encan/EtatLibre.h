#pragma once
#include "EtatObjet.h"
class EtatLibre :
	public EtatObjet
{
public:
	EtatLibre();
	~EtatLibre();

	std::string infoEtat() { return "n'est pas encore vendu"; }
};

