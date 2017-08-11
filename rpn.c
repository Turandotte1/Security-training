#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// check string
int 	ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

int 	ft_isspace(char c)
{
	return (c == ' ' ? 1 : 0); 
}

int		get(char *initial, char *backwards, char **new_backwards)
{
	char 	*temp;
	int 	j;
	int 	k;

	backwards--;
	while (backwards >= initial && ft_isspace(*backwards))
		backwards--;
	temp = backwards;
	while (temp > initial && !ft_isspace(temp[-1]))
		temp--;
	if (temp < initial)
	{
		printf("error\n");
		return (-1);
	}

	#define get_recursive(expr) k = get(initial, temp, (char**)&temp), j = get(initial, temp, (char **)&temp), j = expr
	j = atoi(temp);
	if (backwards <= temp)
	{
		if	(temp[0] == '+') 
			get_recursive(j + k);
		else if (temp[0] == '-') 
			get_recursive(j - k);
		else if (temp[0] == '*') 
			get_recursive(j * k);
		else if (temp[0] == '/') 
			get_recursive(j / k);
		else if (temp[0] == '%') 
			get_recursive(j % k);
	}
	#undef get_recursive

	*(char **)new_backwards = temp;
	return (j);
}

int 		rpn(char *initial)
{
	char *backwards = initial + ft_strlen(initial);		
	int i = get(initial, backwards, (char**)&backwards);

	while (backwards < initial && ft_isspace(backwards[-1]))
		backwards--;
	if (backwards == initial)
		return (i);
	return (-1);
}

int			main(int ac, char **av)
{
	if (ac == 2 && rpn(av[1]) != -1)
		printf("%i\n", rpn(av[1]));
	else
		printf("error\n");
	return (0);
}