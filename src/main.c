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

	cirLabel("Keys", "\
Q: Quit\n\
Enter: Select\n\
W: Up\n\
S: Down\n\
", box, text);

	scolor(text);
	printf("Press any key to continue.");

	keypress();

	char* out = options("\
1\n\
2\n\
3\n\
4\n\
5\n\
6\n\
7\n\
", text, box);

	scolor(text);
	printf("You selected `%s'\n", out);

	free(out);

	printf(RESET);

	return 0;
}
