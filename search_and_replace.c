#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	search_and_replace(char *str, char a, char b)
{
	int i;

	i = 0;
	while(*(str+i))
		*(str+i) == a ? *(str+i) = b : ft_putchar(*(str+i++));
}

int		main(int ac, char **av)
{
	if (ac == 4 && !av[2][1] && !av[3][1])
		search_and_replace(av[1], av[2][0], av[3][0]);
	ft_putchar('\n');
	return (0);
}