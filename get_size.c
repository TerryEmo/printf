#Include "main.h"

/**
 * get_size - Calculates the size to cost the ragument
 * @format: Formatted string
 * @i: List of argument to be printed
 * Return: Precision
 */

int get_size(const char *format, int *i)
{
	int j = *i + 1;
	int size = 0;

	if (format[j] == 'l')
		size = S_LONG;
	else if (format[j] == 'h')
		size = S_SHORT;
	if (size == 0)
		*i = j - 1;
	else
		*i = j;
	return (size);
}
