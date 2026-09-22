# printf Format Specifiers

\* for case sensitive options

|Specifier|Output|Example|
|-|-|-|
|d (or i)| Signed decimal integer	|392
|u|	Unsigned decimal integer	|7235
|o|	Unsigned octal	|610
|x*|	Unsigned hexadecimal integer	|7fa
|f*|	Decimal floating point, lowercase	|392.65
|e*|	Scientific notation (mantissa/exponent), lowercase	|3.9265e+2
|g*|	Use the shortest representation: %e or %f	|392.65
|a*|	Hexadecimal floating point, lowercase	|-0xc.90fep-2
|c|	Character	|a
|s|	String of characters	|sample
|p|	Pointer address	|b8000000
|n|	Nothing printed. The corresponding argument must be a pointer to a signed int. The number of characters written so far is stored in the pointed location.|
|%|	A % followed by another % character will write a single % to the stream.	|%

# ANSI Escape Codes

text effects: `\033[nm`

n|Name
-|-
0|reset
1|bold
3|italic
4|underline
9|strikethrough

- colours taken from the konsole breeze theme
- FG: #fcfcfc
- BG: #232627

FG|BG|colour
-|-|-
30|40|$\color{#232627}\textsf{Black}$
31|41|$\color{#dc2f2f}\textsf{Red}$
32|42|$\color{#11d116}\textsf{Green}$
33|43|$\color{#f67400}\textsf{Yellow}$
34|44|$\color{#1d99f3}\textsf{Blue}$
35|45|$\color{#da88ff}\textsf{Magenta}$
36|46|$\color{#1abc9c}\textsf{Cyan}$
37|47|$\color{#fcfcfc}\textsf{White}$
90|100|$\color{#7f8c8d}\textsf{Bright Black}$
91|101|$\color{#c0392b}\textsf{Bright Red}$
92|102|$\color{#1cdc9a}\textsf{Bright Green}$
93|103|$\color{#fdbc4b}\textsf{Bright Yellow}$
94|104|$\color{#3daee9}\textsf{Bright Blue}$
95|105|$\color{#e9b3ff}\textsf{Bright Magenta}$
96|106|$\color{#16a085}\textsf{Bright Cyan}$
97|107|$\color{#ffffff}\textsf{Bright White}$

24 bit colour

`ESC[38;2;⟨r⟩;⟨g⟩;⟨b⟩m` - RGB foreground colour
`ESC[48;2;⟨r⟩;⟨g⟩;⟨b⟩m` - RGB background colour