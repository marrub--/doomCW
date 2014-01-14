#library "CWKeyFinder"

script "CW_KEYFIND" ENTER
{
	int rel = GetPlayerInput(-1,MODINPUT_BUTTONS) & BT_RELOAD;
	int spd = GetPlayerInput(-1,MODINPUT_BUTTONS) & BT_SPEED;
	int zum = GetPlayerInput(-1,MODINPUT_BUTTONS) & BT_ZOOM;

	int mod = rel+spd+zum;

	switch(mod)
	{
	case BT_RELOAD+BT_SPEED:
		if(!CheckInventory("DNS"))
		{
		if(CheckWeapon("CPistol"))
			ACS_NamedExecuteAlways("CW_ATTACH",0,PIST_SIL);
		if(CheckWeapon("CShotgun")||CheckWeapon("CShotgunSil"))
			ACS_NamedExecuteAlways("CW_ATTACH",0,SHOG_SIL);
		}
		delay(10);
	break;
	case BT_RELOAD:
		if(CheckInventory("CMenu"))
		{
			if(CheckWeapon("CPistolCMenu"))
			{
				if(CheckInventory("CMenuNext"))
				{
					if(CheckInventory("LTrig"))
						ACS_NamedExecuteAlways("CW_ATTACH",0,PIST_TRG);
				}
				else
				{
					if(CheckInventory("Laz"))
						ACS_NamedExecuteAlways("CW_ATTACH",0,PIST_LAZ);
				}
			}
			delay(10);
		}
	break;
	case BT_ZOOM:
		if(CheckWeapon("CPistol"))
			ACS_NamedExecuteAlways("CW_ATTACH",0,CM_PISTL);
		
		delay(10);
	break;
	}
	delay(2);
	restart;
}

