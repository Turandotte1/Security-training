#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int			ft_isblank(char c)
 {
 	if (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v' || c == '\f')
 		return (1);
 	return (0);
 }

int		ft_strlen(char *str)
{
	int len = 0;

	while (str[len])
		len++;
	return(len);
}

void	expand_str(char *str)
{
	int i = 0;
	int j = ft_strlen(str) - 1;

	while (ft_isblank(str[j]))
		j--;
	while (i < j && str[i])
	{
		while (ft_isblank(str[i]))
			i++;
		while (!ft_isblank(str[i]))
			ft_putchar(str[i++]);
		i--;
		if (i != j)
			write(1, "   ", 3);
		i++;
	}
}

int		main(int ac, char **av)
{
	int i;

	i = 1;
	if (ac > 1)
	{
		while (av[i])
			expand_str(av[i++]);
	}
	ft_putchar('\n');
	return (0);
}