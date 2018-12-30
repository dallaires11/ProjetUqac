#pragma once
#include "ObjetAntique.h"
#include "ObjetArt.h"
#include "ObjetService.h"

class ObjetFactory{
private:
	static int instanceObjetFactory;

	ObjetAntique* getObjetAntique();
	ObjetService* getObjetService();
	ObjetArt* getObjetArt();

	std::string typeArt[3];
	std::string typeEtat[3];
	std::string periode[3];
	std::string typeService[5];

	int getValeurArt(int);
	int getRenomme();
	int getDimmension();
	std::string getDescriptionArt(int,int,std::string);
	std::string getTypeArt();//Tablau,sculpture,devoirPOO

	int getValeurOld(int,int);
	int getTypeEtat();
	std::string getDescriptionOld(int,int);
	int getPeriode();

	int getTypeService();
	int getExperience();
	int getTarif(int);
	int getValeurService(int);
	std::string getDescriptionService(int,int,int);

public:
	ObjetFactory();
	~ObjetFactory();

	Objet* getObject(int type);

	static const int getNbInstance() {
		return ObjetFactory::instanceObjetFactory;
	}
};

