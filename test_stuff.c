#include <stdio.h>

typedef struct 	s_opt
{
	int simple;
	int flag;
}				t_opt;	

int		main(void)
{
	t_opt 	*ba;

	ba->simple = 0;
	ba->flag = 0;
	(ba->simple++) ? printf("caca\n") : ba->flag++;
	printf("%d\n", 	ba->flag);
	return(0);
}			