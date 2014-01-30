#library "CWGetVal"

script "CW_GETVAL" (int arg1)
{
	int pis_spdmod = CheckInventory("PistolFSpeedMod");
	int pis_accmod = CheckInventory("PistolAccuracyMod");
	int sht_spdmod = CheckInventory("ShotgunFSpeedMod");
	int sht_sp2mod = CheckInventory("ShotgunPSpeedMod");
	switch(arg1)
	{
	default:
		print(s:"Used default GETVAL value, please report this");
	break;
	case GV_PSTF1:
		SetResultValue(4-pis_spdmod);
	break;
	case GV_PSTF2:
		SetResultValue(5-pis_accmod);
	break;
	case GV_SHTF1:
		SetResultValue(3-sht_spdmod);
	break;
	case GV_SHTP1:
		SetResultValue(5-sht_sp2mod);
	break;
	}
}

