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
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "ao.h"
#include "string.h"

#define VLINE "│"
#define HLINE "─"
#define TLC   "┌"
#define TRC   "┐"
#define BLC   "└"
#define BRC   "┘"
#define CTLC  "╭"
#define CTRC  "╮"
#define CBLC  "╰"
#define CBRC  "╯"

int main ()
{
	struct Color c2 = COLOR_RGB_FG(50, 200, 150);
	struct Color c = COLOR_BOLD_RGB_FG(255, 100, 255);

 	cirNum("\
File:  ./README.md\n\
Style: Moon\n\
hi\n\
hi\n\
hi\n\
hi\n\
hi\n\
hi\n\
hi\n\
hi\n\
", c, c2);

	return 0;
}
