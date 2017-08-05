#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strlen(char *str)
{
	int len = 0;

	while (*(str+len))
		len++;
	return (len);
}

char	*ft_trim(char *str)
{
	int i = 0;
	int j = ft_strlen(str);
	char *cstr;
	int k = 0;

	while (*(str+i) == ' ')
		i++;
	while (*(str+j - 1) == ' ')
		j--;
	cstr = (char*)malloc(sizeof(char) * (j - i + 1));
	while (k < j - i)
	{
		cstr[k] = str[i + k];
		k++;
	}
	cstr[k] = '\0';
	return (cstr);
}

void	epur_str(char *str)
{
	int i = -1;
	int flag;

	str = ft_trim(str);
	flag = 1;
	while (str[++i] != '\0')
	{
		if (str[i] == ' ' && flag == 1)
		{
			ft_putchar(str[i]);
			flag = 0;
		}
		else if (str[i] == ' ' && flag == 0)
			;
		else
		{
			ft_putchar(str[i]);
			flag = 1;
		}
	}
	free(str);
}

int		main(int ac, char **av)
{
	if (ac == 2)
		epur_str(av[1]);
	ft_putchar('\n');
	return (0);
}