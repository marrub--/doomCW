#library "CWAttach"

script "CW_ATTACH"(int arg1)
{
	switch(arg1)
	{
	default:
		print(s:"Warning: Default attachment was used.\nPlease report this.");
	break;
	case SILENCER_PISTOL:
		GiveInventory("Sil_Pistol",1);
	break;
	case SILENCER_CHAINGUN:
		GiveInventory("Sil_Chaingun",1);
	break;
	}
}

script "CW_DETATCH"(int arg1)
{
	switch(arg1)
	{
	default:
		print(s:"Warning: Default detatchment was used.\nPlease report this.");
	break;
	case SILENCER_PISTOL:
		TakeInventory("Sil_Pistol",1);
	break;
	case SILENCER_CHAINGUN:
		TakeInventory("Sil_Chaingun",1);
	break;
	}
}