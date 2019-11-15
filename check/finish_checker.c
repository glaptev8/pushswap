#include "../includes/push_swap.h"

void	finish_check(t_num **a, t_num **b, char **s)
{
	int i;

	i = 0;
	if (!(*a) || (((*a) && !(*a)->next) || ((*a) && (*a)->next && (*a)->next == (*a)) ))
		free((*a));
	else
		clear(a, get_struct_len((*a)) + 1);
	if (!(*b) || (((*b) && !(*b)->next) || ((*b) && (*b)->next && (*b)->next == (*b))))
		free((*b));
	else
		clear(b, get_struct_len((*b)) + 1);
	if (s)
	{
		while (s[i])
			free(s[i++]);
		free(s);
	}
}
