i#include "main.h"

/**
 * handle_write_char - outputs a string
 * @flags: Tracks active flags
 * @precision: specifier
 * @buffer: array of buffer
 * @size: specifier
 * @width: specifier
 * @c: character variable
 * Return: Number of characters printed
 */
int handle_write_char(char c, char buffer[], int flags,
		int width, int precision, int size)
{
	char padd = ' ';
	int i = 0;

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
		padd = '0';

	buffer[i++] = c;
	buffer[i] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (i = 0; i < width - 1; i++)
		{
			buffer[BUFF_SIZE - i - 2] = padd;

			if (flags & F_MINUS)
				return (write(1, &buffer[0], 1)
						+ write(1, &buffer[BUFF_SIZE - i - 1], width - 1));
			else
				return (write(1, &buffer[BUFF_SIZE - i - 1], width - 1)
						+ write(1, &buffer[0], 1));
		}
		return (write(1, &buffer[0], 1));
	}
