#include "../includes/push_swap.h"

int		stacks_is_sort(t_num *a, t_num *b)
{
	int		ferst_a;
	int		ferst_b;
	int 	flag;

	if (!a || !a->next)
		return (1);
	ferst_a = a->num;
	while (a->num < a->next->num)
		a = a->next;
	if (a->next->num != ferst_a)
		return (0);
	if (!b || !b->next)
		return (1);
	if (ferst_a < b->num)
		return (0);
	return (1);
}