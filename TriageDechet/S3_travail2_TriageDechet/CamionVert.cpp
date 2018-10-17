#include "CamionVert.h"

int CamionVert::instanceCamionVert = 0;

CamionVert::CamionVert()
{
	instanceCamionVert++;
}


CamionVert::~CamionVert()
{
	instanceCamionVert--;
}
