#include "../includes/push_swap.h"

void		ft_sa(t_num *a)
{
	int i;
	int num;

	i = a->index;
	num = a->num;
	a->num = a->next->num;
	a->index = a->next->index;
	a->next->num = num;
	a->next->index = i;
}

void		ft_rra(t_num **a)
{
	*a = (*a)->prev;
}

void		ft_rrb(t_num **b)
{
	*b = (*b)->prev;
}

void		ft_pb(t_num **a, t_num **b)
{
	if ((*a)->num != (*b)->num)
	{
		(*b)->num = (*a)->num;
		(*a)->next->prev = (*a)->prev;
		(*a)->prev->next = (*a)->next;
		(*a) = (*a)->next;
	}
	if ((*a)->num == (*b)->num)
	{
		(*a)->num = 0;
		(*a)->next = NULL;
		(*a)->prev = NULL;
	}
}

void		ft_pa(t_num **a, t_num **b)
{
	int		c;
	t_num   *d;

	d = (*a)->prev;
	c = (*a)->prev->num;
	(*a)->prev = lst_create();
	(*a)->prev->num = (*b)->num;
	(*a)->prev->next = d;
	(*a)->prev->prev = d->prev;
	(*a) = (*a)->prev;
		(*b)->next->prev = (*b)->prev;
		(*b)->prev->next = (*b);
		(*b) = (*b)->next;

}