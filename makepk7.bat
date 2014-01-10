@echo OFF
setlocal
set proj_name=doomCW
set proj_path=%~dp0
set proj_path=%proj_path:~0,-1%
set proj_path=%proj_path%\pk7\
rem 7zip path
set comp_path=..\_utils\peazip\res\7z\
set PATH=%PATH%;%comp_path%
7z a out.7z %proj_path%\*
rename out.7z %proj_name%.pk7
endlocal