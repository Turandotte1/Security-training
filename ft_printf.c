#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

typedef struct 		s_args
{
	size_t 	len;
	int		flags;
	int		width;
	int		prec;
	char 	type;
}					t_args;

void	check_flags(const char *format, va_list *ap, size_t *i)
{
//		t_args		*args;
		size_t		j;

..		args = (t_args *)malloc(sizeof(t_args));
		i = 0;
		if (*(format+j) == 's')
			j = str_conv(ap, i);
}

int			ft_printf(const char *format, ...)
{
	size_t 	ret;
	va_list	ap;
	size_t	i;

	ret = 0;
	i = 0;
	va_start(ap, format);
	while(*(format+i))
	{
		if (*(format+i) != '%')
		{
			write(1, &(*(format+i)), 1);
			ret++;
			i++;
		}
		else
			ret = check_flags(format++, &ap, &i);
	}
	va_end(ap);
	return (ret > 2147483647 ? -1 : ret);
}

int		main(int ac, char **av)
{
	ft_printf("my printf\n");
	printf("%d\n", 98);
	return (0);
}