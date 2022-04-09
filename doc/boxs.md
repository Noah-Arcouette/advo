# ?

Puts a box around text


# `void boxText (char* text, struct Color boxc, struct Color textc);`

put a box around `text` set text color to `textc` and box color to `boxc`

box exp 
=======

```
 ____________________
| Hello, world       |
| By: Noah Arcouette |
|____________________|
```


# `void cirText (char* text, struct Color boxc, struct Color textc);`

put a squircle around `text` set text color to `textc` and box color to `boxc`

box exp 
=======

```
╭────────────────────╮
│ Hello, world       │
│ By: Noah Arcouette │
╰────────────────────╯
```


# `void sboxText (char* text, struct Color boxc, struct Color textc);`

put a smooth box around `text` set text color to `textc` and box color to `boxc`

box exp 
=======

```
┌────────────────────┐
│ Hello, world       │
│ By: Noah Arcouette │
└────────────────────┘
```


# Code Section

```C
void boxText  (char*, struct Color, struct Color);
void cirText  (char*, struct Color, struct Color);
void sboxText (char*, struct Color, struct Color);
```
