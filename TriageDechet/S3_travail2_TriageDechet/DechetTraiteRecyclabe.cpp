#include "DechetTraiteRecyclabe.h"

int DechetTraiteRecyclabe::instanceDechetTraiteR = 0;

DechetTraiteRecyclabe::DechetTraiteRecyclabe(Dechet* pseudoDechet) : DechetTraite(pseudoDechet) {
	instanceDechetTraiteR++;
}


DechetTraiteRecyclabe::~DechetTraiteRecyclabe(){
	instanceDechetTraiteR--;
}
