#include <unistd.h>

void	word_find(char *str)
{
	int len;

	while (*str == ' ' || *str == '\t')
		str++;
	len = 0;
	while (str[len] && str[len] != ' ' && str[len] != '\t')
		len++;
	write(1, str, len);
}

int		main(int ac, char **av)
{
	if (ac == 2)
	{
		word_find(av[1]);
	}
	write(1, "\n", 1);
	return 0;
}