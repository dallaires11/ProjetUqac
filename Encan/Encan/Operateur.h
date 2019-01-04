#pragma once
#include"nightTimeException.h"
#include"bankOverloadException.h"
#include"TimeKeeper.h"
#include"Encanteur.h"
class Operateur{
private:
	TimeKeeper* tk;
public:
	Operateur(TimeKeeper*);
	~Operateur();

	void run();
};

