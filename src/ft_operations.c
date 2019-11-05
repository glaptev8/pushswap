#include "../includes/push_swap.h"

t_num		*ft_sa(t_num *a)
{
	int num;

	printf("1 ");
	num = a->num;
	a->num = a->next->num;
	a->next->num = num;
	return (a);
}

t_num		*ft_sb(t_num *b)
{
	printf("2 ");
	int num;

	num = b->num;
	b->num = b->next->num;
	b->next->num = num;
	return (b);
}

t_num		*ft_rra(t_num *a)
{
	printf("3 ");
	a = a->prev;
	return (a);
}

t_num		*ft_rrb(t_num *b)
{
	printf("4 ");
	b = b->prev;
	return (b);
}

t_num		*ft_pb(t_num **a, t_num *b)
{
	printf("5 ");
	b = lst_add(b, (*a)->num);
	(*a) = lst_remove((*a));
	return (b);
}

t_num		*ft_pa(t_num *a, t_num **b)
{
	printf("6 ");
	a = lst_add(a, (*b)->num);
	(*b) = lst_remove((*b));
	return (a);
}