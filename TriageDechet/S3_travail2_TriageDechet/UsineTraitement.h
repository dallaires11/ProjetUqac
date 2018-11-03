#pragma once
#include"SequenceOperation.h"
#include"Depot.h"
#include"ChargementDechet.h"
class UsineTraitement{
private:
	class Log {
		public:
			static void i(std::string info) {
				std::cout << info << std::endl;
			}
			static void i(Dechet const& dechet) {
				std::cout << dechet << std::endl;
			}
			static void i(Depot const& depot) {
				std::cout << depot << std::endl;
			}
	};

	static int instanceUsine;
	SequenceOperation* sequenceOperation;
	Depot depot;
	CamionBleu* camionBleu;
	CamionBrun* camionBrun;
	CamionVert* camionVert;
	friend class OperationTraitement;

	void preOperation() {
		Log::i("Pre Operation");
		return;
	}
	void postOperation() {
		Log::i("Post Operation");
		return;
	}
	void traiterDTC(Dechet* dechet);
	void traiterDTNR(Dechet* dechet);
	void traiterDTR(Dechet* dechet);
	
public:
	UsineTraitement();
	~UsineTraitement();

	void chargerOperation(SequenceOperation*);
	void demmarerTraitement(ChargementDechet*);

	static const int getNbInstance() {
		return UsineTraitement::instanceUsine;
	}
};