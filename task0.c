#include "main.h"
/**
 * _printf - print characters
 * @format: input
 * Return: output
 */
int _printf(const char *format, ...)
{
va_list ap;
const char *s;
int printChars;

va_start(ap, format);

while (*format)
{
if (*format == '%')
{
format++;
if (*format == 'c')
{
putchar(va_arg(ap, int));
printChars++;
}
else if (*format == 's')
{
s = va_arg(ap, const char *);
if (s == NULL)
	s = "(null)";
while (*s)
	putchar(*s);
	s++;
	printChars++;
}
else if (*format == '%')
{
putchar('%');
printChars++;
}
}
else
	putchar(*format);
	printChars++;
format++;
}
va_end(ap);
return (printChars);
}
