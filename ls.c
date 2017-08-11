#include <dirent.h>
#include <stdio.h>



int		ft_ls()
{
	struct dirent 	*banana;
	DIR 			*dir;
	char 			*directory;

	directory = "./";
	dir = opendir(directory);
	if (dir == NULL)
		return 1;
	while ((banana = readdir(dir)) != NULL)
	{
		printf("%s\n", banana->d_name);
	}
	closedir(dir);
	return 0;
}

int		main(int ac, char **av)
{
	char	flags[7];
	int 	i;

	i = 1;
	printf("%s\n", av[i] + 1);
	while (i < ac)
	{
		if (av[i][0] == '-' && av[i][1])
		{
			flag_foo(flags);

		}
	i < ac ? ft_ls_with_flags : ft_ls_without flags;
	return 0;
}