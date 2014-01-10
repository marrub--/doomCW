#library "CWMain"
#include "zcommon.acs"

#define PIST_SIL		0x01
#define PIST_LAZ		0x02
#define CM_PISTL		0x04

#define INT_MAX			0x7FFFFFFF

#include "CWKeyFinder.h"	// Keypress finder
#include "CWAttach.h"		// Attachment and detatchment
#include "CWAtchMenu.h"		// Customization menu
#include "CWLaser.h"		// Laser sight

script "CW_STOPDEATH" DEATH
{
	ACS_NamedTerminate("CW_LASER",0);
	ACS_NamedTerminate("CW_MENUOPEN",0);
	ACS_NamedTerminate("CW_ATTACH",0);
	ACS_NamedTerminate("CW_KEYFIND",0);
}