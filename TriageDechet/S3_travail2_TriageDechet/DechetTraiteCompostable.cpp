#include "DechetTraiteCompostable.h"

int DechetTraiteCompostable::instanceDechetTraiteC = 0;

DechetTraiteCompostable::DechetTraiteCompostable(Dechet* pseudoDechet) : DechetTraite(pseudoDechet){
	instanceDechetTraiteC++;
}


DechetTraiteCompostable::~DechetTraiteCompostable(){
	instanceDechetTraiteC--;
}
