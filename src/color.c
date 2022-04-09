/*
	      _____           ___
	     /  _  \         /  /
	    /  / \  \       /  /
	   /  /___\  \     /  /
	  /  ______\  \   /  /
	 /  /       \  \_/  /
	/__/         \_____/


	This file was made for a Noah Arcouette product.
	https://github.com/Noah-Arcouette

*/
#include "ao.h"
#include <stdio.h>

void scolor (struct Color c)
{
	if (c.flags & __COLOR_BOLD)
		printf("\x1b[1m");

	if (c.flags & __COLOR_BACKGROUND)
		printf("\x1b[48;");
	else
		printf("\x1b[38;");

	if (c.flags & __COLOR_TYPE_RGB)
		printf("2;%d;%d;%dm", c.R, c.G, c.B);
	else
		printf("5;%dm", c.ansi);
}
