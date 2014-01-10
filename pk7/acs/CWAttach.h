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
			TakeInventory("PistolLaz",1);
		else
			GiveInventory("PistolLaz",1);
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
	}
}