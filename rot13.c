#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	rot13(char *str)
{
	int i;

	i = 0;
	while (*(str+i))
	{
		if (*(str+i) >= 'A' && *(str+i) <= 'M')
			*(str+i) = *(str+i) + 13;
		else if (*(str+i) >= 'N' && *(str+i) <= 'Z')
			*(str+i) = *(str+i) - 13;
		else if (*(str+i) >= 'a' && *(str+i) <= 'm')
			*(str+i) = *(str+i) + 13;
		else if (*(str+i) >= 'n' && *(str+i) <= 'z')
			*(str+i) = *(str+i) - 13;
		ft_putchar(*(str+i++));
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
	{
		rot13(av[1]);
	}
	ft_putchar('\n');
	return 0;
}