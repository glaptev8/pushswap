#include "../includes/push_swap.h"

t_num		*ft_sa(t_num *a)
{
	if (a && a->next && a != a->next)
	{
		count++;
		int num;
		num = a->num;
		a->num = a->next->num;
		a->next->num = num;
	}
	return (a);
}

t_num		*ft_sb(t_num *b)
{
	int num;

	if (b && b->next && b->next != b)
	{
		count++;
		num = b->num;
		b->num = b->next->num;
		b->next->num = num;
	}
	return (b);
}

t_num		*ft_ra(t_num *a)
{
	if (a && a->next && a->next != a)
	{
		count++;
		a = a->next;
	}
	return (a);
}

t_num		*ft_rb(t_num *b)
{
	if (b && b->next && b->next != b)
	{
		count++;
		b = b->next;
	}
	return (b);
}

t_num		*ft_rra(t_num *a)
{
	if (a && a->prev && a->prev != a)
	{
		count++;
		a = a->prev;
	}
	return (a);
}

t_num		*ft_rrb(t_num *b)
{
	if (b && b->prev && b->prev != b)
	{
		count++;
		b = b->prev;
	}
	return (b);
}

t_num		*ft_pb(t_num **a, t_num *b)
{
	if ((*a))
	{
		count++;
		b = lst_add(b, (*a)->num);
		if ((*a) && (*a)->next && (*a) != (*a)->next)
			lst_remove(a);
	}
	return (b);
}

t_num		*ft_pa(t_num *a, t_num **b)
{
	int n;
	if (b)
	{
		count++;
		a = lst_add(a, (*b)->num);
		if ((*b)->next)
			lst_remove(b);
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