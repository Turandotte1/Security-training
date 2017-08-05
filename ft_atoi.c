#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int		ft_atoi(char *s)
{
	int	sign;
	long res;

	res = 0;
	while (*s == 32 || (*s >= 9 && *s <= 13))
		s++;
	sign = (*s == '-') ? -1 : 1;
	(*s == '-' || *s == '+') ? s++ : s;
	while (*s >= '0' && *s <= '9')
		res = res * 10 + (*s++ - '0');
	return (sign * (int)res);
}

int		main(int ac, char **av)
{
	printf("true = %d\n", atoi(av[1]));
	printf("my = %d\n", ft_atoi(av[1]));
	return (0);
}