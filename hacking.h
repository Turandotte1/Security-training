void	fatal(char *message)
{
	char	error_message[100];

	strcpy(error_message, "[!!] FATAL ERROR ");
	strncat(error_message, message, 83);
	perror(error_message);
	exit(-1);
}

void	*error_malloc(unsigned int len)
{
	void	*ptr;
	ptr = malloc(len);
	if (ptr == NULL)
		fatal("in error_maloc --> failed memory allocation");
	return (ptr);
}