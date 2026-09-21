# printf format specifiers

\* for case sensitive options

|Specifier|Output|Example|
|-|-|-|
|d| Signed decimal integer	|392
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