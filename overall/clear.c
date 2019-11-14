#include "../includes/push_swap.h"

void	clear(t_num **t, int n)
{
	while (--n > 0 && (*t)->next)
	{
		(*t) = (*t)->next;
		free((*t)->prev);
	}
	free((*t));
}

