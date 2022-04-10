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

#include <unistd.h>
#include <signal.h>
#include <termios.h>

extern size_t strlen (const char* __s);

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

void quit (int)
{
	printf(RESET);
	exit(1);
}

int main ()
{
	signal(SIGINT, quit);

	struct Color text = COLOR_RGB_FG(50, 200, 150);
	struct Color box  = COLOR_BOLD_RGB_FG(255, 100, 255);

	printf(SETUP);
	printf(REFRESH);

	scolor(text);
	cirText("Usage:\nW: up\nS: down\nQ: Quit\nPress anything to continue.\n", box, text);

	keypress();

	char* op = options("Moon\nDesert\nDoxy\n", text, box);


	printf(REFRESH);
	
	scolor(text);
	printf("%s\n", op);

	free(op);

	printf("Good By.\n");

	printf(RESET);

	return 0;
}
