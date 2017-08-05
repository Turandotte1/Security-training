#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	inter(char *a, char *b)
{
	int i;
	int j;
	int flag;

	i = 0;
	while(*(a+i))
	{
		j = 0;
		flag = 0;
		while(*(b+j))
		{
			if(*(a+i) == *(b+j))
			{
				if (flag == 0)
					ft_putchar(*(a+i));
				flag = 1;
				*(b+j) = -1;
			}
			j++;
		}
		i++;
	}
}

int 	main(int argc, char **argv)
{
	if (argc == 3)
		inter(argv[1], argv[2]);
	ft_putchar('\n');
	return 0;
}