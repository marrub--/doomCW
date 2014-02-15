@echo off
color F
setlocal

set acc-path=C:\Users\Graham\Desktop\Utils\dh-acc
set PATH=%PATH%;%acc-path%
set SRC=.\script
set OBJ=.\acs
set CMD=dh-acc --named-scripts --auto-stack-size=0 -Z -i %SRC%\inc -c

echo Compiling DS files...
%CMD% %SRC%\CWAtchMenu.ds -o %OBJ%\CWAtchMenu.o
%CMD% %SRC%\CWAttach.ds -o %OBJ%\CWAttach.o
%CMD% %SRC%\CWGetVal.ds -o %OBJ%\CWGetVal.o
%CMD% %SRC%\CWKeyFinder.ds -o %OBJ%\CWKeyFinder.o
%CMD% %SRC%\CWLaser.ds -o %OBJ%\CWLaser.o
%CMD% %SRC%\CWGetAttachment.ds -o %OBJ%\CWGetAttachment.o
echo Done! Compiling final object file...
dh-acc --named-scripts --auto-stack-size=0 -Z -i %SRC%\inc %OBJ%\CWAtchMenu.o %OBJ%\CWAttach.o %OBJ%\CWGetVal.o %OBJ%\CWKeyFinder.o %OBJ%\CWLaser.o %OBJ%\CWGetAttachment.o -o %OBJ%\CWMain.o
del %OBJ%\CWAtchMenu.o
del %OBJ%\CWAttach.o
del %OBJ%\CWGetVal.o
del %OBJ%\CWKeyFinder.o
del %OBJ%\CWLaser.o
del %OBJ%\CWGetAttachment.o

echo All done! Press any key to exit.

endlocal
pause >nul