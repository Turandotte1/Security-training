#include <stdio.h>

int		is_power_2(unsigned int n)
{
	if (n == 0)
		return (0);
	while (n % 2 == 0)
		n /= 2;
	return ((n == 1) ? 1 : 0);
}

int		main(void)
{
	unsigned int i = 128;
	printf("%d\n", is_power_2(i));
	return (0);
}