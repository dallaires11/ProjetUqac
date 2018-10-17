#include "CamionBleu.h"

int CamionBleu::instanceCamionBleu = 0;

CamionBleu::CamionBleu()
{
	instanceCamionBleu++;
}


CamionBleu::~CamionBleu()
{
	instanceCamionBleu--;
}
