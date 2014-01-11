#library "CWGetVal"

script "CW_GETVAL" (int arg1)
{
	int pis_spdmod = CheckInventory("PistolFSpeedMod");
	int pis_accmod = CheckInventory("PistolAccuracyMod");
	switch(arg1)
	{
	default:
		print(s:"Used default GETVAL value, please report this");
	break;
	case GV_PSTF1:
		SetResultValue(3-pis_spdmod);
	break;
	case GV_PSTF2:
		SetResultValue(5-pis_accmod);
	break;
	}
}

