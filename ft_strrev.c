#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char 	*ft_strrev(char *str)
{
	int i = 0;
	int j = 0;
	char temp;
	while (*(str+j))
		j++;
	j--;
	while (i < j)
	{
		temp = str[j];
		str[j] = str[i];
		str[i] = temp;
		i++;
		j--;
	}
	return (str);
}

int		main(int ac, char **av)
{
	printf("%s\n", ft_strrev(av[1]));
	return (0);
}