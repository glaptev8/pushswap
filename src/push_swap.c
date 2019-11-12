#include "../includes/push_swap.h"
#include <stdlib.h>

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

void	*ft_pushb_a(t_num *b, t_num **a)
{
	while (b != NULL)
	{
		(*a) = ft_pa((*a), &b);
		ft_print((*a), b);
		if (b && b->prev && b->num > b->prev->num)
		{
			b = ft_rrb(b);
			ft_print((*a), b);
		}
		if ((*a)->num > (*a)->prev->num)
		{
			(*a)= ft_ra((*a));
			ft_print((*a), b);
		}
		if ((*a)->num > (*a)->next->num)
		{
			(*a)= ft_sa((*a));
			ft_print((*a), b);
		}
	}
	return ((*a));
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

t_num	*push_swap(t_num *a, t_num **b)
{
	int i = 9;
	while (a->next != NULL && !stacks_is_sort(a, (*b)) && --i > 0)
	{
		if (!sort_one(&a, (*b)))
			break ;
		a = ft_oper(a, b);
	}
	return (ft_pushb_a((*b), &a));
}

int main(int argc, char **argv)
{
	count = 0;
	int n[500];
	int i = 0;
	int j;
//
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
	t_num *a;
	t_num *b;

	a = lst_new(9);
	if (ft_init_stack(&a, argc, argv) == 0)
		ft_putstr_fd("Error\n", 2);
//	while (i < 9)
//	{
//		a->num = n[i];
//		ft_printf("%d  ", a->num);
//		a = a->next;
//		i++;
//	}
//	ft_printf("\n\n\n");
//	b = lst_new(0);
//	b = NULL;
	a = push_swap(a, &b);
	ft_display_a(a);
	i = 9;
	while (--i > 0)
	{
		free(a);
		a = a->next;
	}
//	free(a->next);
//	free(a->next->next);
	free(a);
//	ft_printf("(%d)", count);
//	i = 500;
//	free(b->next);
//	free(b->prev);
//	free(b);
	return 1;
}
