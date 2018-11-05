#pragma once
#include "Dechet.h"
class AssietteJetable :
	public Dechet{
private:
	static int instanceAssiette;
public:
	AssietteJetable();
	AssietteJetable(const AssietteJetable&);
	~AssietteJetable();

	static const int getNbInstance() {
		return AssietteJetable::instanceAssiette;
	}
};

