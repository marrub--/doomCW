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
		if(CheckInventory("Sil_Pistol")||CheckInventory("Sil_Chaingun"))
		{
			if(WepSelected()==WEP_PISTOL)
			{
				ACS_NamedExecuteAlways("CW_DETATCH",0,SILENCER_PISTOL);
			}
			if(WepSelected()==WEP_CHAINGUN)
			{
				ACS_NamedExecuteAlways("CW_DETATCH",0,SILENCER_CHAINGUN);
			}
			delay(10);
		}
		else
		{
			if(WepSelected()==WEP_PISTOL)
			{
				ACS_NamedExecuteAlways("CW_ATTACH",0,SILENCER_PISTOL);
			}
			if(WepSelected()==WEP_CHAINGUN)
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