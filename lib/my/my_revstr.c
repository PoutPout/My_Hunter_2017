/*
** EPITECH PROJECT, 2017
** my_revstr
** File description:
** my_revstr
*/
int	my_strlens(const char *str)
{
	int	i = 0;

	while (str[i] != 0) {
		i = i + 1;
	}
	return (i);
}

char	*my_revstr(char *str)
{
	int	i = 0;
	int	change_letter = 0;
	int	letter = 0;

	i = my_strlens(str) - 1;
	while (letter <= 1) {
		change_letter = str[i];
		str[letter] = str[i];
		str[i] = change_letter;
		letter = letter + 1;
		i = i + 1;
	}
	return (str);
}
