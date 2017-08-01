#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		letter_count(char c)
{
		int count;

		count = 0;
		if (c >= 65 && c <= 90)
			count = c - 64;
		else if (c >= 97 && c <= 122)
			count = c - 96;
		else
			count = 1;
		return (count);
}

int		main(int ac, char **av)
{
	int count;
	int i;
	char *str;

	count = 0;
	i = 0;
	if (ac == 2)
	{
		str = av[1];
		while (str[i])
		{
			count = letter_count(str[i]);
			while (count)
			{
				ft_putchar(str[i]);
				count--;
			}
			i++;
		} 	
	
	}
	write(1, "\n", 1);
	return 0;
}