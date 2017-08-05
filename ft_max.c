#include <stdio.h>

int		max(int *tab, unsigned int len)
{
	int max;

	max = 0;
	while(len--)
	{
		if(tab[len] > max)
			max = tab[len];
	}
	return (max);
}

int		main(void)
{
	int tab[8] = {1, 5, 15, 2, 4, 2, 2, 8};
	printf("%d\n", max(tab, 8));
	return (0); 
}