#pragma once
#include "EtatObjet.h"
class EtatVendu :
	public EtatObjet
{
public:
	EtatVendu();
	~EtatVendu();

	std::string infoEtat() { return "n'est plus disponible"; }
};

