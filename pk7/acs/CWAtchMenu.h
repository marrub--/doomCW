#library "CWAtchMenu"

script "CW_MENUOPEN" (int arg1)
{
	SetHudSize(320,200,0);
	SetFont("DBIGFONT");
	HudMessage(s:"Reload: Attach"; HUDMSG_PLAIN,60,0,160.0,15.0,1.0,1.0);
	SetFont("CMENU");
	int CMenuX;
	int CMenuY;
	if(CheckWeapon("CPistolCMenu")||CheckWeapon("CPistolSilCMenu"))
	{
		CMenuX = 185.0;
		CMenuY = 106.0;
		if(CheckInventory("PistolLaz"))
		{
			SetFont("CMENULAZ");
			HudMessage(s:"A"; HUDMSG_PLAIN|HUDMSG_ALPHA|HUDMSG_NOTWITHFULLMAP,70,0,CMenuX,CMenuY,1.0,1.0);
			SetFont("CMENU1");
		}
		else
			HudMessage(s:""; 0,70,0,0,0,0);
	}
	HudMessage(s:"A"; HUDMSG_PLAIN|HUDMSG_ALPHA|HUDMSG_NOTWITHFULLMAP,71,0,CMenuX,CMenuY,1.0,1.0);
	delay(2);
	restart;
}

script "CW_MENUCLOSE"(int arg1)
{
	ACS_NamedTerminate("CW_MENUOPEN",0);
	HudMessage(s:""; 0,71,0,0,0,0);
	HudMessage(s:""; 0,70,0,0,0,0);
	HudMessage(s:""; 0,60,0,0,0,0);
}