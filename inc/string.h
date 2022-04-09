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
#ifndef __STRING_H__
#define __STRING_H__

#include <stddef.h>

typedef struct
{
	char** data;
	size_t size;
} strarr;

strarr* split     (char*, char);
void    freesplit (strarr*);
size_t  biggest   (strarr*);

#endif
