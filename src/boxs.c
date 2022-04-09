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
#include "string.h"
#include <stdio.h>
#include "ao.h"

extern size_t strlen (const char* __s);

void boxText (char* text, struct Color boxc, struct Color textc)
{
	strarr* sp = split(text, '\n');

	const size_t larg = biggest(sp);

	scolor(boxc);
	printf(" ");

	for (register size_t i = 0; i<(larg+2); i++)
	{
		printf("_");
	}

	printf("\n");

	for (register size_t i = 0; i<sp->size; i++)
	{
		printf("| ");

		scolor(textc);
		printf("%s", sp->data[i]);

		for (size_t j = 0; j<(larg-strlen(sp->data[i])); j++)
		{
			printf(" ");
		}

		scolor(boxc);
		printf(" |\n");
	}

	scolor(boxc);
	printf("|");

	for (register size_t i = 0; i<(larg+2); i++)
	{
		printf("_");
	}

	printf("|" CRES "\n");

	freesplit(sp);
}

void cirText (char* text, struct Color boxc, struct Color textc)
{
	strarr* sp = split(text, '\n');

	const size_t larg = biggest(sp);

	scolor(boxc);
	printf("╭");

	for (register size_t i = 0; i<(larg+2); i++)
	{
		printf("─");
	}

	printf("╮\n");

	for (register size_t i = 0; i<sp->size; i++)
	{
		printf("│ ");

		scolor(textc);
		printf("%s", sp->data[i]);

		for (size_t j = 0; j<(larg-strlen(sp->data[i])); j++)
		{
			printf(" ");
		}

		scolor(boxc);
		printf(" │\n");
	}

	scolor(boxc);
	printf("╰");

	for (register size_t i = 0; i<(larg+2); i++)
	{
		printf("─");
	}

	printf("╯" CRES "\n");

	freesplit(sp);
}

void sboxText (char* text, struct Color boxc, struct Color textc)
{
	strarr* sp = split(text, '\n');

	const size_t larg = biggest(sp);

	scolor(boxc);
	printf("┌");

	for (register size_t i = 0; i<(larg+2); i++)
	{
		printf("─");
	}

	printf("┐\n");

	for (register size_t i = 0; i<sp->size; i++)
	{
		printf("│ ");

		scolor(textc);
		printf("%s", sp->data[i]);

		for (size_t j = 0; j<(larg-strlen(sp->data[i])); j++)
		{
			printf(" ");
		}

		scolor(boxc);
		printf(" │\n");
	}

	scolor(boxc);
	printf("└");

	for (register size_t i = 0; i<(larg+2); i++)
	{
		printf("─");
	}

	printf("┘" CRES "\n");

	freesplit(sp);
}
