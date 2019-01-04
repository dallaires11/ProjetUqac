#pragma once
#include<string>
class EtatObjet{
public:
	EtatObjet();
	virtual ~EtatObjet();

	virtual std::string infoEtat() = 0;
};