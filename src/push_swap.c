#include "../includes/push_swap.h"
#include <stdlib.h>

void	clear(t_num **t, int n)
{
	while (--n > 0 && (*t)->next)
	{
		(*t) = (*t)->next;
		free((*t)->prev);
	}
	free((*t));
}

int		ft_direction(int x, int d, int m, int y)
{
	int to;

	if (x > d && x > m)
		m < d ? d = m : 0;
	else if (d > x && d > m)
		m < x ? x = m : 0;
	else if (m > d && m > x)
	{
		if (d < x)
			x = m;
		else
			d = m;
	}
	if (x > d)
		to = y - x < d ? 2 : 1;
	else if (y - d <= x - 1 || d == y)
		to = 2;
	else
		to = 1;
	return (to);
}

void	ft_pushb_a(t_num **b, t_num **a)
{
	int		q;

//	if ((*b)->next)
//		(*b) = (*b)->next;
	q = get_struct_len((*b));
	while (--q >= 0)
	{
		(*a) = ft_pa((*a), b);
		ft_print((*a), (*b));
		if (q >= 0)
		{
			printf("\n(%d)\n", (*b)->num);
			if ((*b) && (*b)->prev && (*b)->num > (*b)->prev->num)
			{
//				printf("\n(%d)\n", (*b)->num);
				(*b) = (*b)->prev;
				ft_print((*a), (*b));
			}
			if ((*a)->num > (*a)->prev->num)
			{
				(*a)= ft_ra((*a));
				ft_print((*a), (*b));
			}
			if ((*a)->num > (*a)->next->num)
			{
				(*a)= ft_sa((*a));
				ft_print((*a), (*b));
			}
		}
	}
//	(*a) = lst_add((*a), (*b)->num);
//	ft_print((*a), (*b));
//	if ((*a)->num > (*a)->prev->num)
//	{
//		(*a)= ft_ra((*a));
//		ft_print((*a), (*b));
//	}
//	if ((*a)->num > (*a)->next->num)
//	{
//		(*a)= ft_sa((*a));
//		ft_print((*a), (*b));
//	}
//	free(*b);
//	b = NULL;
//	free(b);
}

void	ft_display_a(t_num *a)
{
	int d;

	d = a->num;

	ft_printf("%d ", a->num);
	a = a->next ? a->next : a;
	while (a->next && a->num != d)
	{
		ft_printf("%d ", a->num);
		a = a->next;
	}
	ft_printf ("\n");
}

void	push_swap(t_num **a)
{
	t_num *b;

//	b = ft_pb(a, b);
//	b = ft_pb(a, b);
//	b = ft_pb(a, b);
//	b = ft_pb(a, b);
//	(*a) = ft_pa((*a), &b);
//	b = ft_pb(&q, b);
	while ((*a)->next != (*a) && !stacks_is_sort((*a), b))
	{
		if (!sort_one(a, b))
			return ;
		ft_oper(a, &b);
	}
	ft_pushb_a(&b, a);
}

int main(int argc, char **argv)
{
	count = 0;
	int n[500];
	int i = 0;
	int j;
	t_num *a;

	while (i < 500)
	{
		srand(time(NULL));
		j = 0;
		n[i] = -100 + rand() % 1200;
		while (j < i)
		{
			if (n[j] == n[i])
			{
				n[i] = -100 + rand() % 1200;
				j = -1;
			}
			j++;
		}
		i++;
	}
	i = 0;

	a = lst_new(5);
	if (ft_init_stack(&a, argc, argv) == 0)
		ft_putstr_fd("Error\n", 2);
//	while (i++ < 5)
//	{
//		a->num = n[i];
//		printf("%d  ", a->num);
//		a = a->next;
//	}
	printf("\n");
	push_swap(&a);
//	printf("%d", a->prev->num);
	ft_display_a(a);
	clear(&a, 4);
//	a = NULL;
//	if (a)
//		ft_display_a(a);
	return (1);
}
