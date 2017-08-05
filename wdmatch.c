#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	wdmatch(char *a, char *b)
{
	int i = 0;
	int j;
	int len = 0;
	
	while (a[len])
		len++;
	while (b[i])
	{
		if (a[j] == b[i])
			j++;
		i++;
	}
	if (len == j)
	{
		len = 0;
		while (a[len])
			ft_putchar(a[len++]);
	}
}

int		main(int ac, char **av)
{
	if (ac == 3)
		wdmatch(av[1], av[2]);
	ft_putchar('\n');
	return(0);
}