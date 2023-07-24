#include "main.h"
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
switch (*format)
{
case 'c':
putchar(va_arg(ap, int));
printChars++;
break;
case 's':
{
s = va_arg(ap, const char *);
while (*s)
{
putchar(*s);
s++;
printChars++;
}
}
break;
case '%':
putchar('%');
printChars++;
break;
default:
break;
}
}
else
{
putchar(*format);
printChars++;
}
format++;
}
va_end(ap);
return (printChars);
}

