/*
** EPITECH PROJECT, 2017
** my_putstr
** File description:
** my_putstr
*/


int	my_putstr(char *str)
{
	while (*str)
	{
		my_putchar(*str);
		str = str + 1;
	}
}
