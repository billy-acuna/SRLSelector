# SRLSelector
A simple boot manager for Nintendo DSi.

SRLSelector is a simple boot manager based on the bootstrap from nds-hbmenu by Chishm, WinterMute and highly inspired by FIX94's arm9select.

## Instructions
Put the BOOT.NDS from the release on the root of your SD and create a folder called /SRLSELECTOR, then put your DSi's homebrew inside the 
folder and rename them to the botton you want to assing (Example: B.NDS, DOWN.NDS, START.NDS, etc). Name DEFAULT.NDS the homebrew you want to
autoboot by default, If you want to know what bottons are supported take a look [here.](arm9/source/bootstrap.c#L34-L67) Then simply boot your
favorite dsiwarehax, hold the botton of the homebrew you want (or don't hold anything if you want to run the default) and enjoy.
