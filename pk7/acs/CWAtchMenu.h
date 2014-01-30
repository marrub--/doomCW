#library "CWAtchMenu"

script "CW_MENUOPEN" (int arg1)
{
	/* id index
	 * 30 - selected box
	 * 31 - attachment 1
	 * 32 - attachment 2
	 * 33 - attachment 3
	 * 44 - active attachment 1
	 * 45 - active attachment 2
	 * 46 - active attachment 3
	 * 68 - how to use text
	 * 71 - c-menu
	 */
	
	SetHudSize(320,200,0);
	SetFont("DBIGFONT");
	HudMessage(s:"Reload:Attach\nFire:Switch"; 0,67,0,160.0,15.0,1.0);
	int CMenuX, CMenuY, wep1;
	int atch1 = 0;
	
	if(CheckInventory("LTrig"))
		atch1 = 0x10;
	if(CheckInventory("Laz"))
		atch1 = atch1 + 0x20;
	if(CheckInventory("PumpMech"))
		atch1 = atch1 + 0x40;
	
	switch(arg1)
	{
	case 1: // PISTOL
		wep1 = 0x10;
		CMenuX = 185.0;
		CMenuY = 106.0;
		if(atch1 & 0x10)
			SprPrint("CMENUTRG", 31, CMenuX, CMenuY);
		if(atch1 & 0x20)
			SprPrint("CMENULAZ", 32, CMenuX, CMenuY);
		
		if(CheckInventory("PistolLTrig"))
			SprPrint("CMENU3", 44, CMenuX-1.0, CMenuY-30.0);
		if(CheckInventory("PistolLaz"))
			SprPrint("CMENU3", 45, CMenuX-1.0, CMenuY-23.0);
	break;
	
	case 2: // SHOTGUN
		wep1 = 0x20;
		CMenuX = 128.0;
		CMenuY = 102.0;
		
		if(atch1 & 0x10)
			SprPrint("CMENUTRG", 31, CMenuX, CMenuY);
		if(atch1 & 0x20)
			SprPrint("CMENULAZ", 32, CMenuX, CMenuY);
		if(atch1 & 0x40)
			SprPrint("CMENUPMP", 33, CMenuX, CMenuY);
		
		if(CheckInventory("ShotgunLTrig"))
			SprPrint("CMENU3", 44, CMenuX-1.0, CMenuY-30.0);
		if(CheckInventory("ShotgunLaz"))
			SprPrint("CMENU3", 45, CMenuX-1.0, CMenuY-23.0);
		if(CheckInventory("ShotgunPump"))
			SprPrint("CMENU3", 46, CMenuX-1.0, CMenuY-16.0);
	break;
	}
	
	int CMenu2Y = CMenuY - (30.0 - (7.0 * CheckInventory("CMenuNext")));
	SprPrint("CMENU2", 30, CMenuX-1.0, CMenu2Y);
	SprPrint("CMENU1", 71, CMenuX, CMenuY);
	delay(1);
	for(int i = 30; i < 71; i++)
		ClearMsg(i);
	restart;
}

script "CW_MENUCLOSE" (void)
{
	ACS_NamedTerminate("CW_MENUOPEN",0);
	for(int i = 30; i < 72; i++)
		ClearMsg(i);
}