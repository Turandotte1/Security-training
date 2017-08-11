#include <stdio.h>

int		main(void)
{
	printf("4567 |%-10]5d| plip\n", 12);
    printf("4567 |%10]5d| plip\n", 12);
    printf("|%10.5d|\n", -12);
    printf("|%10d|\n", -12);
    printf("|%010d|\n", -12); 
    printf("|%-10.5d|\n", -12);
    printf("|%-010.5d|\n", -12);
}