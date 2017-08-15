#include "list.h"

t_list		*ft_create_elem(void *data)
{
	t_list	*new;

	if(!(new = (t_list *)malloc(sizeof(new))))
		return (-1);
	new->data = data;
	new->next = NULL;
	return (new);
}