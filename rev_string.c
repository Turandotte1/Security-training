#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	rev_print(char *str)
{
	int count;

	count = 0;
	while (str[count])
		count++;
	while (count >= 0)
	{
		ft_putchar(str[count--]);
	}
}

int 	main(int ac, char **av)
{
	if (ac == 2)
	{
		rev_print(av[1]);
	}
	ft_putchar('\n');
	return 0;
}