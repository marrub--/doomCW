#library "CWAtchMenu"

str atchnames[2][2] =
{
	{"PistolLTrig", "ShotgunLTrig"},
	{"PistolLaz", "ShotgunLaz"},
};

script "CW_MENUOPEN" (int arg1)
{
	/* id index
	 * 65 - active attachment 2
	 * 66 - active attachment 1
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
	int atch1, atch2 = 0;
	
	if(CheckInventory("Laz"))
		atch1 = 0x10;
	if(CheckInventory("LTrig"))
		atch1 = atch1 + 0x20;
	for(int i1 = 0; i1 < 1; i1++)
		if(CheckInventory(atchnames[0][i1])&&!CheckInventory(atchnames[1][i1]))
			atch2 = 0x10000;
	for(int i2 = 0; i2 < 1; i2++)
		if(CheckInventory(atchnames[1][i2])&&!CheckInventory(atchnames[0][i2]))
			atch2 = 0x20000;
	for(int i3 = 0; i3 < 1; i3++)
		if(CheckInventory(atchnames[0][i3])&&CheckInventory(atchnames[1][i3]))
			atch2 = 0x30000;
	
	switch(arg1)
	{
	case 1: // PISTOL
		wep1 = 0x10;
		CMenuX = 185.0;
		CMenuY = 106.0;
		if(atch1 & 0x10)
			SprPrint("CMENULAZ", 70, CMenuX, CMenuY);
		if(atch1 & 0x20)
			SprPrint("CMENUTRG", 69, CMenuX, CMenuY);
	break;
	
	case 2: // SHOTGUN
		wep1 = 0x20;
		CMenuX = 128.0;
		CMenuY = 102.0;
		if(atch1 & 0x10)
			SprPrint("CMENULAZ", 70, CMenuX, CMenuY);
		if(atch1 & 0x20)
			SprPrint("CMENUTRG", 69, CMenuX, CMenuY);
	break;
	}
	
	switch(CheckInventory("CMenuNext") + wep1 + atch2)
	{
	// Offsets are 7 apart
	case 0x10020:
	case 0x10010:
	case 0x20:
	case 0x10:
		SprPrint("CMENU2", 68, CMenuX-1.0, CMenuY-30.0);
	break;
	
	case 0x20021:
	case 0x20011:
	case 0x21:
	case 0x11:
		SprPrint("CMENU2", 68, CMenuX-1.0, CMenuY-23.0);
	break;
	
	case 0x30021:
	case 0x30011:
	case 0x10021:
	case 0x10011:
		SprPrint("CMENU3", 66, CMenuX-1.0, CMenuY-30.0);
		SprPrint("CMENU2", 68, CMenuX-1.0, CMenuY-23.0);
	break;
	
	case 0x30020:
	case 0x30010:
	case 0x20020:
	case 0x20010:
		SprPrint("CMENU2", 68, CMenuX-1.0, CMenuY-30.0);
		SprPrint("CMENU3", 65, CMenuX-1.0, CMenuY-23.0);
	break;
	}
	
	SprPrint("CMENU1", 71, CMenuX, CMenuY);
	delay(2);
	for(int i = 65; i < 71; i++)
		ClearMsg(i);
	restart;
}

script "CW_MENUCLOSE" (void)
{
	ACS_NamedTerminate("CW_MENUOPEN",0);
	for(int i = 65; i < 72; i++)
		ClearMsg(i);
}

