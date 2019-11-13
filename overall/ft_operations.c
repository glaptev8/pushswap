#include "../includes/push_swap.h"

t_num		*ft_sa(t_num *a)
{
	count++;
	int num;

	num = a->num;
	a->num = a->next->num;
	a->next->num = num;
	return (a);
}

t_num		*ft_sb(t_num *b)
{
	count++;
	int num;

	num = b->num;
	b->num = b->next->num;
	b->next->num = num;
	return (b);
}

t_num		*ft_ra(t_num *a)
{
	count++;
	a = a->next;
	return (a);
}

t_num		*ft_rb(t_num *b)
{
	count++;
	if (b->next)
		b = b->next;
	return (b);
}

t_num		*ft_rra(t_num *a)
{
	count++;
	a = a->prev;
	return (a);
}

t_num		*ft_rrb(t_num *b)
{
	count++;
	b = b->prev;
	return (b);
}

t_num		*ft_pb(t_num **a, t_num *b)
{
    count++;
    b = lst_add(b, (*a)->num);
	lst_remove(a);
	return (b);
}

t_num		*ft_pa(t_num *a, t_num **b)
{
	int n;

	count++;
	a = lst_add(a, (*b)->num);
	if ((*b)->next)
		lst_remove(b);
	else
	{
		b = NULL;
	}
	return (a);
}

void	ft_rrr(t_num **a, t_num **b)
{
	(*a) = ft_rra((*a));
	(*b) = ft_rrb((*b));
}

void	ft_rr(t_num **a, t_num **b)
{
	(*a) = ft_ra((*a));
	(*b) = ft_ra((*b));
}