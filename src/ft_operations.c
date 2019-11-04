#include "../includes/push_swap.h"

t_num		*ft_sa(t_num *a)
{
	int num;

	num = a->num;
	a->num = a->next->num;
	a->next->num = num;
	return (a);
}

t_num		*ft_rra(t_num *a)
{
	a = a->prev;
	return (a);
}

void		ft_rrb(t_num **b)
{
	*b = (*b)->prev;
}

t_num		*ft_pb(t_num **a, t_num *b)
{
	b = lst_add(b, (*a)->num);
	(*a) = lst_remove((*a));
	return (b);
}

void		ft_pa(t_num **a, t_num **b)
{
}