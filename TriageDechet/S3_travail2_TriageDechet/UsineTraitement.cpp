#include "UsineTraitement.h"

int UsineTraitement::instanceUsine = 0;

UsineTraitement::UsineTraitement(){
	instanceUsine++;
}


UsineTraitement::~UsineTraitement(){
	instanceUsine--;
}
