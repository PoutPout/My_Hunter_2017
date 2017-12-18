/*
** EPITECH PROJECT, 2017
** my_put_nbr_base
** File description:
** my_put_nbr_base
*/


int my_put_nbr_base(unsigned int cont ,char *base) {
unsigned int nb_base;
unsigned int conv;
unsigned int rest;

nb_base = my_strlen(base);
rest = cont % nb_base;
conv = cont / nb_base;
if (conv != 0)
{
my_put_nbr_base(conv, base);
}
my_putchar(base[rest]);
}
