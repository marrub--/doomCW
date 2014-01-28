#library "CWAtchMenu"

script "CW_MENUOPEN" (int arg1)
{
	/* id index
	 * 67 - how to use text
	 * 68 - selected box
	 * 69 - attachment 1
	 * 70 - attachment 2
	 * 71 - c-menu
	 */
	SetHudSize(320,200,0);
	SetFont("DBIGFONT");
	HudMessage(s:"Reload:Attach\nFire:Switch"; 0,67,0,160.0,15.0,1.0);
	int CMenuX, CMenuY, wep1;
	
	switch(arg1)
	{
	case 1: // PISTOL
		wep1 = 0x10;
		CMenuX = 185.0;
		CMenuY = 106.0;
		if(CheckInventory("PistolLaz"))
			SprPrint("CMENULAZ", 70, CMenuX, CMenuY);
		if(CheckInventory("PistolLTrig"))
			SprPrint("CMENUTRG", 69, CMenuX, CMenuY);
	break;
	case 2: // SHOTGUN
		wep1 = 0x20;
		CMenuX = 128.0;
		CMenuY = 102.0;
		if(CheckInventory("ShotgunLaz"))
			SprPrint("CMENULAZ", 70, CMenuX, CMenuY);
		if(CheckInventory("ShotgunLTrig"))
			SprPrint("CMENUTRG", 69, CMenuX, CMenuY);
	break;
	}
	
	switch(CheckInventory("CMenuNext") + wep1)
	{
	// Offsets are 7 apart
	case 0x20:
	case 0x10:
		SprPrint("CMENU2", 68, CMenuX-1.0, CMenuY-30.0);
	break;
	case 0x21:
	case 0x11:
		SprPrint("CMENU2", 68, CMenuX-1.0, CMenuY-23.0);
	break;
	}
	
	SprPrint("CMENU1", 71, CMenuX, CMenuY);
	delay(2);
	ClearMsg(70); ClearMsg(69);
	restart;
}

script "CW_MENUCLOSE" (void)
{
	ACS_NamedTerminate("CW_MENUOPEN",0);
	for(int i = 67; i < 72; i++)
		ClearMsg(i);
}

