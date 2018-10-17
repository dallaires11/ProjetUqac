#include "DechetTraite.h"

int DechetTraite::instanceDechetTraite = 0;

DechetTraite::DechetTraite(Dechet* pseudoDechet){
	dechet = pseudoDechet;
	instanceDechetTraite++;
}


DechetTraite::~DechetTraite(){
	delete dechet;
	instanceDechetTraite--;
}

const Dechet* DechetTraite::getDechet() {
	return dechet;
}