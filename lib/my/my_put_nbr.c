/*
** EPITECH PROJECT, 2017
** my_put_nbr.c
** File description:
** my_put_nbr.c
*/
int	my_put_nbr(int nb)
{
	if (nb < 0) {
		my_putchar('-');
		nb = -nb;
	}
	if (nb >= 10) {
		my_put_nbr(nb / 10);
	 }
	my_putchar((nb % 10)+ '0');
	return(0);
}
