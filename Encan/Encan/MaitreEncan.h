#pragma once
#include<iomanip>
#include<iostream>
#include<thread>
#include"Encan.h"
#include"SalleAttente.h"
#include"VendeurFactory.h"
#include"AcheteurFactory.h"
#include"Bouncer.h"
#include"TimeKeeper.h"
#include"Logger.h"
#include"Operateur.h"
using namespace std;
class MaitreEncan{
private:
	SalleAttente* salleAtt;
	Bouncer* bouncer;
	TimeKeeper* tk;
	AcheteurFactory* aFactory;
	VendeurFactory* vFactory;
	Operateur* op;

	void ouvertureEncan();

public:
	MaitreEncan();
	~MaitreEncan();
};