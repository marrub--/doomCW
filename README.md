Channel: irc://irc.esper.net/#doomcw

Features
========
To attach Silencers
-------------------
	Hold RUN and RELOAD to attach or detatch a Silencer.

To use the Customization Menu
-----------------------------
	Press ZOOM to open the Customization Menu.
	Press RELOAD to attach an Attachment.
	Press FIRE to scroll the menu.

How to play
===========
Option 1:
* Go to the releases page and download the latest release there.

Option 2:
* Clone the repository (Download ZIP on the main page)
* Zip the pk7/ folder contents
* Rename the zip to doomcw.pk3

ACS Stuff
=========
Definitions in CWMain.c
-----------------------
Used as an argument for the CW_ATTACH script
- PIST_SIL
- PIST_LAZ
- PIST_TRG
- CM_PISTL
- SHOG_SIL
- SHOG_LAZ
- SHOG_TRG
- CM_SHTGN
Used as an argument for the CW_GETVAL script
- GV_PSTF1
- GV_PSTF2
- GV_SHTF1

Maximum integer
- INT_MAX

Scripts
-------
- CW_KEYFIND - Looping script that checks some buttons and does stuff in a switch
- CW_ATTACH - Huge-ass switch that does some CheckInventory comparisons
- CW_MENUOPEN - Terminatable looping script that opens the Customization Menu.
- CW_MENUCLOSE - Terminates CW_MENUOPEN and closes the HudMessages.
- CW_GETVAL - Switch to be used in DECORATE for gun modifications.
- CW_LASER - Looping script that spawns a laser pointer if you have one attached
