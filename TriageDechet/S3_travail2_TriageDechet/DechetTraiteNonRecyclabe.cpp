#include "DechetTraiteNonRecyclabe.h"

int DechetTraiteNonRecyclabe::instanceDechetTraiteNR = 0;

DechetTraiteNonRecyclabe::DechetTraiteNonRecyclabe(Dechet* pseudoDechet) : DechetTraite(pseudoDechet) {
	instanceDechetTraiteNR++;
}

DechetTraiteNonRecyclabe::DechetTraiteNonRecyclabe(const DechetTraiteNonRecyclabe& pseudoNonRecyclable) : DechetTraite(pseudoNonRecyclable.dechet) {
	instanceDechetTraiteNR++;
}


DechetTraiteNonRecyclabe::~DechetTraiteNonRecyclabe(){
	instanceDechetTraiteNR--;
}
