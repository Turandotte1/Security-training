#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		check(char *s, char c, int i)
{
	int a;

	a = 0;
	while(a < i)
	{
		if (*(s+a) == c)
			return (0);
		a++;
	}
	return (1);
}

void	ft_union(char *a, char *b)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (*(a+i))
	{
		if (check(a, *(a+i), i))
			ft_putchar(*(a+i));
		i++;
	}
	while (*(b+j))
	{
		if (check(b, *(b+j), j) && check(a, *(b+j), i))
			ft_putchar(*(b+j));
		j++;
	}
}

int		main(int ac, char **av)
{
	if (ac == 3)
		ft_union(av[1], av[2]);
	ft_putchar('\n');
	return (0);
}