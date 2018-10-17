#pragma once
#include "Dechet.h"
class DechetTraite{
private:
	static int instanceDechetTraite;
protected:
	Dechet* dechet;
public:
	DechetTraite(Dechet*);
	virtual ~DechetTraite();

	const Dechet* getDechet();

	static const int getNbInstance() {
		return DechetTraite::instanceDechetTraite;
	}
};

