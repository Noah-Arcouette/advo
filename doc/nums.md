# ?

numbers lines in a box iwth text on side


# `void boxNum (char* text, struct Color boxc, struct Color textc);`

numbers with a box with `text` set text color to `textc` and box color to `boxc`

box exp 
=======

```
__
1 | Hello, world
2 | By: Noah Arcouette
__|
```


# `void cirNum (char* text, struct Color boxc, struct Color textc);`

numbers with a squircle with `text` set text color to `textc` and box color to `boxc`

box exp 
=======

```
──╮
1 │ Hello, world
2 │ By: Noah Arcouette
──╯
```


# `void sboxNum (char* text, struct Color boxc, struct Color textc);`

numbers with a smooth box with `text` set text color to `textc` and box color to `boxc`

box exp 
=======

```
──┐
1 │ Hello, world
2 │ By: Noah Arcouette
──┘
```


# Code Section

```C
void boxNum  (char*, struct Color, struct Color);
void sboxNum (char*, struct Color, struct Color );
void cirNum  (char*, struct Color, struct Color);
```
