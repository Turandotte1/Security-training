#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strlen(char *str)
{
	int len = 0;

	while (str[len])
		len++;
	return(len);
}

int		isblanc(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

void	epur_str(char *str)
{
	int i = 0;
	int len = ft_strlen(str);

	while (len && isblanc(*(str+(len-1))))
		--len;
	while (len && isblanc(*(str+i)) && *(str+i))
	{
		--len;
		i++;
	}
	while (len)
	{
		if (!isblanc(*(str+i)) || (*(str+i+1) && !isblanc(*(str+i+1))))
			ft_putchar(*(str+i));
		i++;
		len--;
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
		epur_str(av[1]);
	ft_putchar('\n');
	return (0);
}