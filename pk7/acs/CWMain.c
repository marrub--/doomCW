#library "CWMain"

#include "zcommon.acs"

// Definitions
#include "CWDefs.h"

#include "CWKeyFinder.h" // Keypress finder
#include "CWAttach.h" // Attachment and detatchment

function int WepSelected(void)
{
	if (CheckWeapon("CPistol")) return WEP_PISTOL;
	if (CheckWeapon("Chaingun")) return WEP_CHAINGUN;
	if (CheckWeapon("Fist")) return WEP_FIST;
	return WEP_NULL;
}