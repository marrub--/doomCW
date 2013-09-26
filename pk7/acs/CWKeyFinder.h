#library "CWKeyFinder"

script "CW_KEYFIND" ENTER
{
	while(1)
	{
	int mod1 = GetPlayerInput(-1,MODINPUT_BUTTONS) & BT_RELOAD;
	int mod2 = GetPlayerInput(-1,MODINPUT_BUTTONS) & BT_SPEED;

	int modifier = mod1+mod2;

	switch(modifier) // I'm sure there's a better way to do this, right?
	{
	case BT_RELOAD+BT_SPEED:
		if(WepSelected()==WEP_PISTOL)
		{
			if(CheckInventory("Sil_Pistol"))
			{
				ACS_NamedExecuteAlways("CW_DETATCH",0,SILENCER_PISTOL);
			}
			else
			{
				ACS_NamedExecuteAlways("CW_ATTACH",0,SILENCER_PISTOL);
			}
			delay(10);
		}
		if(WepSelected()==WEP_CHAINGUN)
		{
			if(CheckInventory("Sil_Chaingun"))
			{
				ACS_NamedExecuteAlways("CW_DETATCH",0,SILENCER_CHAINGUN);
			}
			else
			{
				ACS_NamedExecuteAlways("CW_ATTACH",0,SILENCER_CHAINGUN);
			}
			delay(10);
		}
	break;
	}
	delay(2);
	}
}