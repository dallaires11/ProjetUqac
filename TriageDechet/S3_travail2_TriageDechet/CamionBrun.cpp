#include "CamionBrun.h"

int CamionBrun::instanceCamionBrun = 0;

CamionBrun::CamionBrun()
{
	instanceCamionBrun++;
}


CamionBrun::~CamionBrun()
{
	instanceCamionBrun--;
}
