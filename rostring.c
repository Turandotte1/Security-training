#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int		ft_isblank(char c)
{
	if (c == '\t' || c == ' ')
		return (1);
	return (0);
}

void	rostring(char *str)
{
	int i = 0;
	int w = 0;
	int j;

	while (ft_isblank(str[i]))
		i++;
	while (!(ft_isblank(str[i])))
	{
	 	i++;
	 	w++;
	}
	while (str[i])
	{
		while (ft_isblank(str[i]))
			i++;
		while (!ft_isblank(str[i]) || (str[i + 1] && !ft_isblank(str[i + 1])))
		{
			write(1, &str[i], 1);
			i++;
		}
		j = 0;
		while (j < w)
		{
			write(1, &str[j], 1);
			j++;
		}
		i++;
	}	
}

int		main(int ac, char **av)
{
	int i = 1;
	if (ac > 1)
	{
		while (av[i])
			rostring(av[i++]);
	}
	write(1, "\n", 1);
	return (0);
}