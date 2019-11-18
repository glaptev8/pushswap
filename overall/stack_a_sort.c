#include "../includes/push_swap.h"

int		is_a_sort(t_num *a)
{
	t_num *b;

	b = a;
	if (a && a->next && a->next == a)
		return (1);
	while (a && a->next && a->next != b)
	{
		if (a->num > a->next->num)
			return (0);
		a = a->next;
	}
	return (1);
}