/*-----------------------------------------------------------------

 Copyright (C) 2010  Dave "WinterMute" Murphy

 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 2
 of the License, or (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

------------------------------------------------------------------*/

#include <nds.h>
#include <fat.h>

#include <stdio.h>

#include "nds_loader_arm9.h"

int main( int argc, char **argv) {
	consoleDemoInit();
	scanKeys();

	if(fatInitDefault()) {
	if(keysDown() & KEY_A) {
		runNdsFile("/SRLSELECTOR/A.NDS", 0, NULL);
	} else if(
		keysDown() & KEY_B) {
		runNdsFile("/SRLSELECTOR/B.NDS", 0, NULL);
	} else if(
		keysDown() & KEY_SELECT) {
		runNdsFile("/SRLSELECTOR/SELECT.NDS", 0, NULL);
	} else if(
		keysDown() & KEY_START) {
		runNdsFile("/SRLSELECTOR/START.NDS", 0, NULL);
	} else if(
		keysDown() & KEY_RIGHT) {
		runNdsFile("/SRLSELECTOR/RIGHT.NDS", 0, NULL);
	} else if(
		keysDown() & KEY_LEFT) {
		runNdsFile("/SRLSELECTOR/LEFT.NDS", 0, NULL);
	} else if(
		keysDown() & KEY_UP) {
		runNdsFile("/SRLSELECTOR/UP.NDS", 0, NULL);
	} else if(
		keysDown() & KEY_DOWN) {
		runNdsFile("/SRLSELECTOR/DOWN.NDS", 0, NULL);
	} else if(
		keysDown() & KEY_R) {
		runNdsFile("/SRLSELECTOR/R.NDS", 0, NULL);
	} else if(
		keysDown() & KEY_L) {
		runNdsFile("/SRLSELECTOR/L.NDS", 0, NULL);
	} else if(
		keysDown() & KEY_X) {
		runNdsFile("/SRLSELECTOR/X.NDS", 0, NULL);
	} else if(
		keysDown() & KEY_Y) {
		runNdsFile("/SRLSELECTOR/Y.NDS", 0, NULL);
	} else
		runNdsFile("/SRLSELECTOR/DEFAULT.NDS", 0, NULL);
	} else {
		printf("FAT init failed!\n");
	}
	while(1) swiWaitForVBlank();
}
