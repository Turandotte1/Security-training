#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int		get(char *banana, char *str, char **new_str)
{
	char *t;
	int a;
	int b;

	str--;
	while (str >= banana && isspace(*str))
		str--;
	t = str;
	while (t > banana && !isspace(t[-1]))
		t--;
	if (t < banana)
	{
		printf("error\n");
		return (1);
	}

	#define get_recursive(expr) b = get(banana, t, (char**)&t), a = get(banana, t, (char **)&t), a = expr

	a = atoi(t);
	if (str <= t)
	{
		if	(t[0] == '+') 
			get_recursive(a + b);
		else if (t[0] == '-') 
			get_recursive(a - b);
		else if (t[0] == '*') 
			get_recursive(a * b);
		else if (t[0] == '/') 
			get_recursive(a / b);
		else if (t[0] == '%') 
			get_recursive(a % b);
	}

	#undef get_recursive

	*(char **)new_str = t;
	return (a);
}

int		rpn(char *banana)
{
	char *str = banana + strlen(banana);
	int a = get(banana, str, (char**)&str);

	while (str < banana && isspace(str[-1]))
		str--;
	if (str == banana)
		return (a);
	return (42);
}

int		main(int ac, char **av)
{
	if (ac == 2 && rpn(av[1]) != 42)
	{
		printf("%i\n", rpn(av[1]));
	}
	else
		printf("error\n");
	return 0;
}
	