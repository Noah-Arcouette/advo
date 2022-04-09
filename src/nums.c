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
#include <string.h>
#include "string.h"
#include "ao.h"

size_t digits (size_t size)
{
	register size_t num = 0;

	for (; size; size /= 10)
	{
		num++;
	}

	return num;
}

void boxNum (char* text, struct Color boxc, struct Color textc)
{
	strarr* sp = split(text, '\n');

	scolor(boxc);

	for (register size_t i = 0; i<digits(sp->size)+1; i++)
	{
		printf("_");
	}

	printf("\n");

	for (register size_t i = 0; i<sp->size; i++)
	{
		scolor(textc);
		printf("%zu ", i+1);

		for (size_t j = 0; j<(digits(sp->size)-digits(i+1)); j++)
		{
			printf(" ");
		}

		scolor(boxc);
		printf("| ");

		scolor(textc);
		printf("%s", sp->data[i]);

		scolor(boxc);
		printf(" \n");
	}

	scolor(boxc);

	for (register size_t i = 0; i<digits(sp->size)+1; i++)
	{
		printf("_");
	}

	printf("|" CRES "\n");

	freesplit(sp);
}

void sboxNum (char* text, struct Color boxc, struct Color textc)
{
	strarr* sp = split(text, '\n');

	scolor(boxc);

	for (register size_t i = 0; i<digits(sp->size)+1; i++)
	{
		printf("─");
	}

	printf("┐\n");

	for (register size_t i = 0; i<sp->size; i++)
	{
		scolor(textc);
		printf("%zu ", i+1);

		for (size_t j = 0; j<(digits(sp->size)-digits(i+1)); j++)
		{
			printf(" ");
		}

		scolor(boxc);
		printf("│ ");

		scolor(textc);
		printf("%s", sp->data[i]);

		scolor(boxc);
		printf(" \n");
	}

	scolor(boxc);

	for (register size_t i = 0; i<digits(sp->size)+1; i++)
	{
		printf("─");
	}

	printf("┘" CRES "\n");

	freesplit(sp);
}

void cirNum (char* text, struct Color boxc, struct Color textc)
{
	strarr* sp = split(text, '\n');

	scolor(boxc);

	for (register size_t i = 0; i<digits(sp->size)+1; i++)
	{
		printf("─");
	}

	printf("╮\n");

	for (register size_t i = 0; i<sp->size; i++)
	{
		scolor(textc);
		printf("%zu ", i+1);

		for (size_t j = 0; j<(digits(sp->size)-digits(i+1)); j++)
		{
			printf(" ");
		}

		scolor(boxc);
		printf("│ ");

		scolor(textc);
		printf("%s", sp->data[i]);

		scolor(boxc);
		printf(" \n");
	}

	scolor(boxc);

	for (register size_t i = 0; i<digits(sp->size)+1; i++)
	{
		printf("─");
	}

	printf("╯" CRES "\n");

	freesplit(sp);
}