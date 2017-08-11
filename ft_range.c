#include <stdlib.h>
#include <stdio.h>

int		*ft_range(int start, int end)
{
	int *tab;
	int i;

	i = 0;
	tab = ((int*)malloc(sizeof(int) * (end - start) + 3));
	while (start <= end)
	{
		tab[i] = start;
		start++;
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

int		main(void)
{
	int i = 8;
	int j = 20;
	int a = 0;
	int *tab = ft_range(i, j);

	while (a <= (j - i))
	{
		printf("%d\n", tab[a++]);
	}
	return 0;
}