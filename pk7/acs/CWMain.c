#library "CWMain"
#include "zcommon.acs"

#define PIST_SIL		1
#define PIST_LAZ		2
#define PIST_TRG		4
#define CM_PISTL		8

#define GV_PSTF1		1
#define GV_PSTF2		2

#define INT_MAX			0x7FFFFFFF

#include "CWKeyFinder.h"	// Key press finder
#include "CWAttach.h"		// Attachment and detatchment
#include "CWAtchMenu.h"		// Customization menu
#include "CWGetVal.h"		// Value grabber
#include "CWLaser.h"		// Laser sight