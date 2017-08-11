#include <unistd.h>

int		ft_strlen(char *str)
{
	int i = 0;

	while (*(str+i))
		i++;
	return(i);
}
void	hidenp(char *a, char *b)
{
	int i = 0;
	int j = 0;
	while (*(b+i))
	{
		if (*(b+i) == *(a+j))
			j++;
		i++;
	}
	if (j == ft_strlen(a))
		write(1, "1", 1);
	else
		write(1, "0", 1);
}

int		main(int ac, char **av)
{
	if (ac == 3)
		hidenp(av[1], av[2]);
	write(1, "\n", 1);
	return (0);
}