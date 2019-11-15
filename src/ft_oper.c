#include "../includes/push_swap.h"

t_num		*ft_sa(t_num *a)
{
	int num;

	if (a && a->next && a != a->next)
	{
		printf("sa\n");
		count++;
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
		printf("sb\n");
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
		printf("ra\n");
		count++;
		a = a->next;
	}
	return (a);
}

t_num		*ft_rb(t_num *b)
{
	if (b && b->next && b->next != b)
	{
		printf("rb\n");
		count++;
		b = b->next;
	}
	return (b);
}

t_num		*ft_rra(t_num *a)
{
	if (a && a->prev && a->prev != a)
	{
		printf("rra\n");
		count++;
		a = a->prev;
	}
	return (a);
}

t_num		*ft_rrb(t_num *b)
{
	if (b && b->prev && b->prev != b)
	{
		printf("rrb\n");
		count++;
		b = b->prev;
	}
	return (b);
}

t_num		*ft_pb(t_num **a, t_num *b)
{
	printf("pb\n");
	count++;
	b = lst_add(b, (*a)->num);
	if ((*a) && (*a)->next && (*a) != (*a)->next)
		lst_remove(a);
	return (b);
}

t_num		*ft_pa(t_num *a, t_num **b)
{
	int n;

	printf("pa\n");
	count++;
	a = lst_add(a, (*b)->num);
	if ((*b)->next)
		lst_remove(b);
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