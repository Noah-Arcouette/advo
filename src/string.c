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
#include <stdlib.h>
// #include <string.h>

extern char *strcpy (char *__restrict __dest, const char *__restrict __src);
extern size_t strlen (const char *__s);
extern char *strncat (char *__restrict __dest, const char *__restrict __src, size_t __n) __THROW __nonnull ((1, 2));

strarr* split (char* string, char delimiter)
{
	strarr* sp = (strarr*)malloc(sizeof(strarr));

	sp->data = (char**)NULL;
	sp->size = 0;

	char* current = (char*)malloc(1 * sizeof(char));
	current[0] = '\0';
	register size_t csz = 1;

	for (register size_t i = 0; string[i]!='\0'; i++)
	{
		if (string[i] == delimiter)
		{
			if (csz > 1)
			{
				sp->data = (char**)realloc(sp->data, 
					(++sp->size) * sizeof(char*));

				sp->data[sp->size-1] = (char*)malloc(sizeof(char) * csz);
				strcpy(sp->data[sp->size-1], current);

				current = (char*)realloc(current, 1 * sizeof(char));
				current[0] = '\0';
				csz = 1;
			}

			continue;
		}

		current = (char*)realloc(current, (++csz) * sizeof(char));
		strncat(current, &string[i], 1);
	}

	if (csz > 1)
	{
		sp->data = (char**)realloc(sp->data, 
			(++sp->size) * sizeof(char*));

		sp->data[sp->size-1] = (char*)malloc(sizeof(char) * csz);
		strcpy(sp->data[sp->size-1], current);
	}

	free(current);

	return sp;
}

void freesplit (strarr* sp)
{
	for (; sp->size;)
	{
		free(sp->data[--sp->size]);
	}
	free(sp->data);
	free(sp);
}

size_t biggest (strarr* sp)
{
	register size_t max = 0;
	register ssize_t j;

	for (register size_t i = 0; i<sp->size; i++)
	{
		j = strlen(sp->data[i]);

		// if (j > max)
		// 	max = j;

		// branchless version
		j -= (ssize_t)max;
		max += (size_t)((j > 0) * j);
	}

	return max;
}
