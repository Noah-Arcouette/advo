#include <stdio.h>
#include "ao.h"

extern size_t strlen (const char* __s);

void line (char* text, size_t len, struct Color boxc, struct Color textc)
{
	const size_t pad = len-strlen(text);

	scolor(boxc);
	for (register size_t i = 0; i<pad/2; i++)
		printf("─");

	scolor(textc);
	printf(text);

	scolor(boxc);
	for (register size_t i = 0; i<pad/2+pad%2; i++)
		printf("─");

	printf("\n");
}
