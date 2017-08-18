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
#include <sys/stat.h>
#include <string.h>

#include "nds_loader_arm9.h"

int file_exists(char const* path) {
	struct stat st;
	if(stat(path, &st) == 0)
		return 1; // File exists
	return 0;
}

void panic() {
	const char* defnds = "/SRLSELECTOR/DEFAULT.NDS";
	if(file_exists(defnds)
		runNdsFile(defnds, 0, NULL);
	printf("No payload found! :(\n");
}

int main( int argc, char **argv) {
	consoleDemoInit();
	scanKeys();
	int keys = keysDown();

	if(!fatInitDefault()) {
		printf("FAT init failed!\n");
		goto fail; // Bail out early
	}
	char buf[80] = {0};
	strcat(buf, "/SRLSELECTOR/");
	char *payload = NULL;
	if(keys & KEY_A)
		payload = "A.NDS";
	else if(keys & KEY_B)
		payload = "B.NDS";
	else if(keys & KEY_SELECT)
		payload = "SELECT.NDS";
	else if(keys & KEY_START)
		payload = "START.NDS";
	else if(keys & KEY_RIGHT)
		payload = "RIGHT.NDS";
	else if(keys & KEY_LEFT)
		payload = "LEFT.NDS";
	else if(keys & KEY_UP)
		payload = "UP.NDS";
	else if(keys & KEY_DOWN)
		payload = "DOWN.NDS";
	else if(keys & KEY_R)
		payload = "R.NDS";
	else if(keys & KEY_L)
		payload = "L.NDS";
	else if(keys & KEY_X)
		payload = "X.NDS";
	else if(keys & KEY_Y)
		payload = "Y.NDS";
	else
		panic();
	strcat(buf, payload);
	if(!file_exists(buf))
		panic();
	runNdsFile(buf, 0, NULL);
fail:
	while(1) swiWaitForVBlank();
}
