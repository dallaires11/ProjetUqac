#pragma once
#include"SequenceOperation.h"
#include"Depot.h"
#include"ChargementDechet.h"
class UsineTraitement{
private:
	class Log {
		void i(std::string info) {
			std::cout << info << std::endl;
		}
		void i(Dechet const& dechet);
		void i(Depot const& depot);
	};
	static int instanceUsine;
	SequenceOperation* sequenceOperation;
	Depot depot;
	CamionBleu* camionBleu;
	CamionBrun* camionBrun;
	CamionVert* camionVert;
	void preOperation() {
		//Log::i("Pre Operation");
		return;
	}
	void postOperation() {
		//Log::i("Post Operation");
		return;
	}
	void traiterDTC(Dechet* dechet);
	void traiterDTNR(Dechet* dechet);
	void traiterDTR(Dechet* dechet);
	void traiterDechet(Dechet* dechet);

	
public:
	UsineTraitement();
	~UsineTraitement();

	void chargerOperation(SequenceOperation*);
	void demmarerTraitement(ChargementDechet*);

	static const int getNbInstance() {
		return UsineTraitement::instanceUsine;
	}
};