#library "CWMain"
#include "zcommon.acs"

#define PIST_SIL	1
#define PIST_LAZ	2
#define PIST_TRG	3
#define CM_PISTL	4
#define SHOG_SIL	5
#define SHOG_LAZ	6
#define SHOG_TRG	7
#define CM_SHTGN	8

#define GV_PSTF1	1
#define GV_PSTF2	2
#define GV_SHTF1	3

#define INT_MAX		0x7FFFFFFF

// All of these are for CWAttach.h
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

function void SItmFunc2 (str arg1)
{
	if(CheckInventory(arg1))
	{
		TakeInventory(arg1,1);
	}
	else
	{
		GiveInventory(arg1,1);
	}
}

function void CWepFunc (str arg1, str arg2)
{
	if(CheckWeapon(arg1))
	{
		GiveInventory(arg2,1);
		SetWeapon(arg2);
	}
}

// Useful functions
function void SprPrint(str sprite, int id, int x, int y)
{
	SetFont(sprite);
	HudMessage(s:"A"; HUDMSG_PLAIN, id, CR_UNTRANSLATED, x, y, 1.0);
}

function void SprPrintFade(str sprite, int id, int x, int y, int d, int h)
{
	SetFont(sprite);
	HudMessage(s:"A"; HUDMSG_FADEOUT, id, CR_UNTRANSLATED, x, y, d, h);
}

function void ClearMsg(int id)
{
	HudMessage(s:""; 0,id,0,0,0,0);
}

#include "CWKeyFinder.h"	// Key press thing
#include "CWAttach.h"		// Attachment and detatchment
#include "CWAtchMenu.h"		// Customization menu
#include "CWGetVal.h"		// Value grabber
#include "CWLaser.h"		// Laser sight