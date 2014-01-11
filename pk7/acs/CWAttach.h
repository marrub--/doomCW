#library "CWAttach"

script "CW_ATTACH" (int arg1)
{
	switch(arg1)
	{
	default:
		print(s:"Warning: Default attachment was used.\nPlease report this.");
	break;
	case PIST_SIL:
		if(CheckInventory("CPistolSil"))
		{
			GiveInventory("CPistolToNorm",1);
			SetWeapon("CPistolToNorm");
		}
		else
		{
			GiveInventory("CPistolToSil",1);
			SetWeapon("CPistolToSil");
		}
	break;
	case PIST_LAZ:
		if(CheckInventory("PistolLaz"))
		{
			TakeInventory("PistolAccuracyMod",1);
			TakeInventory("PistolLaz",1);
		}
		else
		{
			GiveInventory("PistolAccuracyMod",1);
			GiveInventory("PistolLaz",1);
		}
	break;
	case PIST_TRG:
		if(CheckInventory("PistolLTrig"))
		{
			TakeInventory("PistolFSPeedMod",1);
			TakeInventory("PistolLTrig",1);
		}
		else
		{
			GiveInventory("PistolFSPeedMod",1);
			GiveInventory("PistolLTrig",1);
		}
	break;
	case CM_PISTL:
		if(CheckWeapon("CPistolSil"))
		{
			GiveInventory("CPistolSilCMenu",1);
			SetWeapon("CPistolSilCMenu");
		}
		if(CheckWeapon("CPistol"))
		{
			GiveInventory("CPistolCMenu",1);
			SetWeapon("CPistolCMenu");
		}
	break;
	case SHOG_SIL:
		if(CheckInventory("CShotgunSil"))
		{
			GiveInventory("CShotgunToNorm",1);
			SetWeapon("CShotgunToNorm");
		}
		else
		{
			GiveInventory("CShotgunToSil",1);
			SetWeapon("CShotgunToSil");
		}
	break;
	}
}

