#pragma once
#include <stack>
#include"Dechet.h"
class Camion{
private:
	static int instanceCamion;
	int capaciteMax;
	int capacite;
	std::stack <Dechet> dechetTraite;
protected:
public:
	Camion();
	~Camion();
};

