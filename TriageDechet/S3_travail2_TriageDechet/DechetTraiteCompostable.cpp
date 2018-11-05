#include "DechetTraiteCompostable.h"

int DechetTraiteCompostable::instanceDechetTraiteC = 0;

DechetTraiteCompostable::DechetTraiteCompostable(Dechet* pseudoDechet) : DechetTraite(pseudoDechet){
	instanceDechetTraiteC++;
}

DechetTraiteCompostable::DechetTraiteCompostable(const DechetTraiteCompostable& pseudoCompostable) : DechetTraite(pseudoCompostable.dechet) {
	instanceDechetTraiteC++;
}


DechetTraiteCompostable::~DechetTraiteCompostable(){
	instanceDechetTraiteC--;
}
