# ?

control terminal colors


# Colors with RGB

## `COLOR_RGB_FG(r, g, b)`

return `struct Color` with foreground set to `r`, `g`, and `b` values

## `COLOR_RGB_BG(r, g, b)`

return `struct Color` with background set to `r`, `g`, and `b` values

## `COLOR_BOLD_RGB_FG(r, g, b)`

return `struct Color` with foreground set to `r`, `g`, and `b` values and bold

## `COLOR_BOLD_RGB_BG(r, g, b)`

return `struct Color` with background set to `r`, `g`, and `b` values and bold


# Colors with 255 ANSI codes

## `COLOR_ANSI_FG(ansi)`

return `struct Color` with foreground set to `ansi`

## `COLOR_ANSI_BG(ansi)`

return `struct Color` with background set to `ansi`

## `COLOR_BOLD_ANSI_FG(ansi)`

return `struct Color` with foreground set to `ansi` and bold

## `COLOR_BOLD_ANSI_BG(ansi)`

return `struct Color` with background set to `ansi` and bold


# Else

## `void scolor (struct Color);`

set terminal color to `struct Color`

## `CRES`

color reset string


# Exps

```C
#include <stdio.h>
#include <advo.h>

int main ()
{
	struct Color fg = COLOR_BOLD_RGB_FG(255, 100, 255);
	struct Color bg = COLOR_ANSI_BG(240);

	scolor(fg);
	scolor(bg);

	printf("Hello, world!\n" CRES);

	return 0;
}
```


# Code Section

```C
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
```