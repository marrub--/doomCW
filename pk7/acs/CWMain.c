#library "CWMain"
#include "zcommon.acs"

#define PIST_SIL		1
#define PIST_LAZ		2
#define PIST_TRG		4
#define CM_PISTL		8
#define SHOG_SIL		16

#define GV_PSTF1		1
#define GV_PSTF2		2

#define INT_MAX			0x7FFFFFFF

function void SWepFunc (str arg1, str arg2, str arg3)
{
	if(CheckInventory(arg1))
	{
		GiveInventory(arg2,1);
		SetWeapon(arg2);
	}
	else
	{
		GiveInventory(arg3,1);
		SetWeapon(arg3);
	}
}

function void SItmFunc (str arg1, str arg2)
{
	if(CheckInventory(arg1))
	{
		TakeInventory(arg2,1);
		TakeInventory(arg1,1);
	}
	else
	{
		GiveInventory(arg2,1);
		GiveInventory(arg1,1);
	}
}

#include "CWKeyFinder.h"	// Key press finder
#include "CWAttach.h"		// Attachment and detatchment
#include "CWAtchMenu.h"		// Customization menu
#include "CWGetVal.h"		// Value grabber
#include "CWLaser.h"		// Laser sight