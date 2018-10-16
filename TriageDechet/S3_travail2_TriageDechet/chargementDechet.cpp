#include "chargementDechet.h"

chargementDechet::chargementDechet(){
	current = 0;
	setDechet();
}


chargementDechet::~chargementDechet(){

}

void chargementDechet::setDechet() {
	listeDechet[0] = new PancarteElectorale();
	listeDechet[1] = new Bouteille();
	listeDechet[2] = new Ustensile();
	listeDechet[3] = new Canette();
	listeDechet[4] = new Plante();
	listeDechet[5] = new Bureau();
	listeDechet[6] = new Bouffe();
	listeDechet[7] = new Devoir();
	listeDechet[8] = new AssietteJetable();
	listeDechet[9] = new Bardeau();
	/*
	listeDechet[10] = new Dechet;
	listeDechet[11] = new Dechet;
	listeDechet[12] = new Dechet;
	listeDechet[13] = new Dechet;
	listeDechet[14] = new Dechet;
	listeDechet[15] = new Dechet;
	listeDechet[16] = new Dechet;
	listeDechet[17] = new Dechet;
	listeDechet[18] = new Dechet;
	listeDechet[19] = new Dechet;
	listeDechet[20] = new Dechet;
	listeDechet[21] = new Dechet;
	listeDechet[22] = new Dechet;
	listeDechet[23] = new Dechet;
	listeDechet[24] = new Dechet;
	listeDechet[25] = new Dechet;
	listeDechet[26] = new Dechet;
	listeDechet[27] = new Dechet;
	listeDechet[28] = new Dechet;
	listeDechet[29] = new Dechet;
	listeDechet[30] = new Dechet;
	listeDechet[31] = new Dechet;
	listeDechet[32] = new Dechet;
	listeDechet[33] = new Dechet;
	listeDechet[34] = new Dechet;
	listeDechet[35] = new Dechet;
	listeDechet[36] = new Dechet;
	listeDechet[37] = new Dechet;
	listeDechet[38] = new Dechet;
	listeDechet[39] = new Dechet;
	listeDechet[40] = new Dechet;
	listeDechet[41] = new Dechet;
	listeDechet[42] = new Dechet;
	listeDechet[43] = new Dechet;
	listeDechet[44] = new Dechet;
	listeDechet[45] = new Dechet;
	listeDechet[46] = new Dechet;
	listeDechet[47] = new Dechet;
	listeDechet[48] = new Dechet;
	listeDechet[49] = new Dechet;
	*/

	return;
}

Dechet* chargementDechet::getDechet() {
	return listeDechet[current++];
}