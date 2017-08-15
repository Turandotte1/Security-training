#include "list.h"

int		ft_list_size(t_list	*begin_list)
{
	t_list	*link;
	int		len = 0;

	link = begin_list;
	if (link)
	{
		size = 1;
		while (link->next)
		{
			link = link->next;
			len++
		}

	}
	return (len);
}