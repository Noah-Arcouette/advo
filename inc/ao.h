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
#ifndef __AO_H__
#define __AO_H__

#include <stdint.h>
#include <stddef.h>

#define RESET   "\x1b[?25h\x1b[?47l"
#define REFRESH "\x1b[2J\x1b[H"
#define SETUP   "\x1b[?25l\x1b[?47h"

#define __COLOR_TYPE_RGB   0b1
#define __COLOR_BACKGROUND 0b10
#define __COLOR_BOLD       0b100
struct Color
{
	uint8_t ansi;

	uint8_t R;
	uint8_t G;
	uint8_t B;

	uint8_t flags:3;
};

void scolor (struct Color);

#define COLOR_ANSI_FG(ansi) { ansi, 0, 0, 0, 0 };
#define COLOR_ANSI_BG(ansi) { ansi, 0, 0, 0, __COLOR_BACKGROUND };
#define COLOR_RGB_FG(r, g, b)  { 0, r, g, b, __COLOR_TYPE_RGB };
#define COLOR_RGB_BG(r, g, b)  { 0, r, g, b, __COLOR_TYPE_RGB | __COLOR_BACKGROUND };

#define COLOR_BOLD_ANSI_FG(ansi) { ansi, 0, 0, 0, 0, __COLOR_BOLD };
#define COLOR_BOLD_ANSI_BG(ansi) { ansi, 0, 0, 0, __COLOR_BACKGROUND | __COLOR_BOLD };
#define COLOR_BOLD_RGB_FG(r, g, b)  { 0, r, g, b, __COLOR_TYPE_RGB | __COLOR_BOLD };
#define COLOR_BOLD_RGB_BG(r, g, b)  { 0, r, g, b, __COLOR_TYPE_RGB | __COLOR_BACKGROUND | __COLOR_BOLD };


#define CRES "\x1b[0m"


void boxText  (char*, struct Color, struct Color);
void cirText  (char*, struct Color, struct Color);
void sboxText (char*, struct Color, struct Color);

void boxNum  (char*, struct Color, struct Color);
void sboxNum (char*, struct Color, struct Color );
void cirNum  (char*, struct Color, struct Color);

void line (char*, size_t, struct Color, struct Color);

void boxLabel  (char*, char*, struct Color, struct Color);
void sboxLabel (char*, char*, struct Color, struct Color);
void cirLabel  (char*, char*, struct Color, struct Color);

#ifdef __linux__
	int keypress ();
	char* options (char*, struct Color, struct Color);
#else
#	warning "Not in linux options and keypress are not defined"
#endif

#endif
