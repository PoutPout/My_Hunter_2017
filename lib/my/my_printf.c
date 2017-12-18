/*
** EPITECH PROJECT, 2017
** main for printf function
** File description:
** main for printf function
*/

#include <stdarg.h>
int	my_printf(char *cont , ...)
{
	va_list list;
	int n = 0;

	va_start(list, cont);
	while (cont[n] != '\0') {
		if(cont[n] == '%')
		{
			n++;
			if (cont[n] == 'X') {
				n++;
				my_put_nbr_base((va_arg(list, unsigned int)), "0123456789ABCDEF");
			}
			else if (cont[n] == 'x') {
				n++;
				my_put_nbr_base((va_arg(list, unsigned int)), "0123456789abcdef");
			}
			else if (cont[n] == 'b') {
				n++;
				my_put_nbr_base((va_arg(list, unsigned int)), "01");
			}
			else if (cont[n] == 'u')
			{
				n++;
				my_put_nbr_base((va_arg(list, unsigned int)), "0123456789");
			}
			else if (cont[n] == 'o')
			{
				n++;
				my_put_nbr_base((va_arg(list, unsigned int)), "01234567");
			}
			else if(cont[n] == 's')
			{
				n++;
				my_putstr(va_arg(list, char *));
			}
			else if(cont[n] == 'c')
			{
				n++;
				my_putchar((char) va_arg(list, int));
			}
			else if(cont[n] == 'i' || cont[n] == 'd')
			{
				n++;
				my_put_nbr(va_arg(list, int));
			}else {
				//my_putchar('%');
			}
		}
		my_putchar(cont[n]);
		n++;
	}

	va_end(list);
}
