#include "string.h"
#include "ao.h"
#include <stdio.h>
#include <stdlib.h>

extern size_t strlen (const char* __s);
extern char *strcpy (char *__restrict __dest, const char *__restrict __src);
extern char *strncat (char *__restrict __dest, const char *__restrict __src, size_t __n) __THROW __nonnull ((1, 2));


int keypress() 
{
	system("/bin/stty raw");
	int c;
	system("/bin/stty -echo");
	c = getc(stdin);
	system("/bin/stty echo");
	system("/bin/stty cooked");
	return c;
}

char* options (char* opts, struct Color boxc, struct Color textc)
{
	strarr* sp = split(opts, '\n');

	const size_t larg = biggest(sp);

	char* data = malloc(1);
	data[0] = 0;

	int c = 0;
	size_t p = 1;
	while (c != 'q')
	{
		printf(REFRESH);

		if (c == 'w' && (p-1) > 0)
			p--;

		if (c == 's' && p < sp->size)
			p++;

		if (c == '\r')
		{
			data = malloc(strlen(sp->data[p-1]) * sizeof(char));
			strcpy(data, sp->data[p-1]);
			break;
		}


		for (register size_t i = 0; i<sp->size; i++)
		{
			if (p == i+1)
			{
				line(sp->data[i], (larg*3)+2, textc, boxc);
			}
			else
			{
				line(sp->data[i], larg*3, boxc, textc);
			}
		}

		c = keypress();
	}

	freesplit(sp);

	return data;
}
