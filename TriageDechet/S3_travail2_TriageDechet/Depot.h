#pragma once
#include"CamionBleu.h"
#include"CamionBrun.h"
#include"CamionVert.h"
class Depot{
private:
	static int instanceDepot;
	int totalDTR;
	int totalDTNR;
	int totalDTC;
public:
	Depot();
	~Depot();

	CamionBleu* getCamionBleu();
	CamionBrun* getCamionBrun();
	CamionVert* getCamionVert();
	void depotDechetTraite(CamionBleu*);
	void depotDechetTraite(CamionBrun*);
	void depotDechetTraite(CamionVert*);

	static const int getNbInstance() {
		return Depot::instanceDepot;
	}

	friend std::ostream& operator<<(std::ostream& out, const Depot& depot);
};