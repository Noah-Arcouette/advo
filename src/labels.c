#include "string.h"
#include "ao.h"
#include <stdio.h>

extern size_t strlen (const char* __s);

void cirLabel (char* title, char* text, struct Color boxc, struct Color textc)
{
	strarr* sp = split(text, '\n');

	size_t larg = biggest(sp);
	size_t pad = strlen(title);

	if (pad > larg) larg = pad;

	pad = larg-strlen(title)+2;

	scolor(boxc);
	printf("╭");

	for (register size_t i = 0; i<pad/2; i++)
	{
		printf("─");
	}

	printf(title);

	for (register size_t i = 0; i<pad/2+pad%2; i++)
	{
		printf("─");
	}

	printf("╮\n");

	for (register size_t i = 0; i<sp->size; i++)
	{
		pad = larg-strlen(sp->data[i]);

		printf("│ ");

		for (size_t j = 0; j<pad/2; j++)
		{
			printf(" ");
		}

		scolor(textc);
		printf("%s", sp->data[i]);

		for (size_t j = 0; j<pad/2+pad%2; j++)
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

void sboxLabel (char* title, char* text, struct Color boxc, struct Color textc)
{
	strarr* sp = split(text, '\n');

	size_t larg = biggest(sp);
	size_t pad = strlen(title);

	if (pad > larg) larg = pad;

	pad = larg-strlen(title)+2;
	scolor(boxc);
	printf("┌");

	for (register size_t i = 0; i<pad/2; i++)
	{
		printf("─");
	}

	printf(title);

	for (register size_t i = 0; i<pad/2+pad%2; i++)
	{
		printf("─");
	}

	printf("┐\n");

	for (register size_t i = 0; i<sp->size; i++)
	{
		pad = larg-strlen(sp->data[i]);

		printf("│ ");

		for (size_t j = 0; j<pad/2; j++)
		{
			printf(" ");
		}

		scolor(textc);
		printf("%s", sp->data[i]);

		for (size_t j = 0; j<pad/2+pad%2; j++)
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

void boxLabel (char* title, char* text, struct Color boxc, struct Color textc)
{
	strarr* sp = split(text, '\n');

	size_t larg = biggest(sp);
	size_t pad = strlen(title);

	if (pad > larg) larg = pad;

	pad = larg-strlen(title)+2;

	scolor(boxc);
	printf(" ");

	for (register size_t i = 0; i<pad/2; i++)
	{
		printf("_");
	}

	printf(title);

	for (register size_t i = 0; i<pad/2+pad%2; i++)
	{
		printf("_");
	}

	printf("\n");

	for (register size_t i = 0; i<sp->size; i++)
	{
		pad = larg-strlen(sp->data[i]);

		printf("| ");

		for (size_t j = 0; j<pad/2; j++)
		{
			printf(" ");
		}

		scolor(textc);
		printf("%s", sp->data[i]);

		for (size_t j = 0; j<pad/2+pad%2; j++)
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
