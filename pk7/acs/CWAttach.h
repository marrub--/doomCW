#library "CWAttach"

script "CW_ATTACH" (int arg1)
{
	switch(arg1)
	{
	default:
		print(s:"Warning: Default attachment was used.\nPlease report this.");
	break;
	case PIST_SIL:
		SWepFunc("PistolSil", "CPistolToNorm", "CPistolToSil");
	break;
	case PIST_LAZ:
		SItmFunc("PistolLaz", "PistolAccuracyMod");
	break;
	case PIST_TRG:
		SItmFunc("PistolLTrig", "PistolFSpeedMod");
	break;
	case CM_PISTL:
		if(CheckWeapon("CPistol"))
		{
			GiveInventory("CPistolCMenu",1);
			SetWeapon("CPistolCMenu");
		}
	break;
	case SHOG_SIL:
		SWepFunc("ShotgunSil", "CShotgunToNorm", "CShotgunToSil");
	break;
	}
}

