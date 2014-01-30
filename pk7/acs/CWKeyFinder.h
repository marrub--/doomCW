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
		if(CheckWeapon("CShotgun"))
			ACS_NamedExecuteAlways("CW_ATTACH",0,SHOG_SIL);
		}
		delay(10);
	break;
	case BT_RELOAD:
		if(CheckInventory("CMenu"))
		{
			if(CheckWeapon("CPistolCMenu"))
			{
				switch(CheckInventory("CMenuNext"))
				{
				case 0:
					if(CheckInventory("LTrig"))
						ACS_NamedExecuteAlways("CW_ATTACH",0,PIST_TRG);
				break;
				case 1:
					if(CheckInventory("Laz"))
						ACS_NamedExecuteAlways("CW_ATTACH",0,PIST_LAZ);
				break;
				}
			}
			if(CheckWeapon("CShotgunCMenu"))
			{
				switch(CheckInventory("CMenuNext"))
				{
				case 0:
					if(CheckInventory("LTrig"))
						ACS_NamedExecuteAlways("CW_ATTACH",0,SHOG_TRG);
				break;
				case 1:
					if(CheckInventory("Laz"))
						ACS_NamedExecuteAlways("CW_ATTACH",0,SHOG_LAZ);
				break;
				case 2:
					if(CheckInventory("PumpMech"))
						ACS_NamedExecuteAlways("CW_ATTACH",0,SHOG_PMP);
				break;
				}
			}
			delay(10);
		}
	break;
	case BT_ZOOM:
		if(CheckWeapon("CPistol"))
			ACS_NamedExecuteAlways("CW_ATTACH",0,CM_PISTL);
		if(CheckWeapon("CShotgun"))
			ACS_NamedExecuteAlways("CW_ATTACH",0,CM_SHTGN);
		
		delay(10);
	break;
	}
	delay(2);
	restart;
}

