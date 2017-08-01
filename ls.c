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

int		main(void)
{
	ft_ls();
	return 0;
}