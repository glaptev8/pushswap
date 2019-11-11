#include "../includes/push_swap.h"
#include <stdlib.h>

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

void	ft_print(t_num *a, t_num *b)
{
	int o;
	int d;

	o = a->num;
	printf("%-9d", o);
	if (a->next)
		a = a->next;
	if (b)
	{
		d = b->num;
		printf("%d", d);
		b = b->next;
	}
	printf("\n");
	while (a->num != o || (b && b->next && b->num != d))
	{
		if (a->num != o)
		{
			printf("%-9d", a->num);
			a = a->next;
		}
		else printf("         ");
		if (b && b->index == -1 && b->next && b->num != d)
		{
			printf("%d", b->num);
		}
		if (b && b->next && b->num != d)
			b = b->next;
		printf("\n");
	}
	printf("---------------------------------\n");
}

int		ft_abs(int n)
{
	if (n > 0)
		return (n);
	return (-n);
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

	printf("%d ", a->num);
	a = a->next ? a->next : a;
	while (a->next && a->num != d)
	{
		printf("%d ", a->num);
		a = a->next;
	}
	printf ("\n");
}

int		sort_one(t_num **a, t_num *b)
{
	if (stacks_is_sort((*a)->next, b))
	{
		(*a) = ft_ra((*a));
		ft_print((*a), b);
		return (0);
	}
	if (stacks_is_sort((*a)->prev, b))
	{
		(*a) = ft_rra((*a));
		ft_print((*a), b);
		return (0);
	}
	return (1);
}

int		get_min(t_num *a)
{
	t_num *q;
	int min;

	min = a->num;
	q = a->next;
	while (q != a)
	{
		if (q->num < min)
			min = q->num;
		q = q->next;
	}
	return (min);
}

int		get_max(t_num *a)
{
	t_num *q;
	int max;

	max = a->num;
	q = a->next;
	while (q != a)
	{
		if (q->num > max)
			max = q->num;
		q = q->next;
	}
	return (max);
}

int		get_second_min(t_num *a, int min)
{
	int m;
	t_num *q;

	m = a->num;
	q = a->next;
	while (q != a)
	{
		if (q->num < m && q->num != min)
			m = q->num;
		q = q->next;
	}
	return (m);
}

int		get_pos(t_num *a, int n)
{
	int i;

	i = 0;
	while (a->num != n)
	{
		i++;
		a = a->next;
	}
	return (i);
}

int		get_struct_len(t_num *a)
{
	t_num *q;
	int i;

	i = 0;
	q = a->next;
	while (q != a)
	{
		i++;
		q = q->next;
	}
	return (i);
}

t_num	*step(int to, int min, t_num *a)
{
	if (to == 1 && a->num != min)
		a = ft_ra(a);
	else if (a->num != min)
		a = ft_rra(a);
	return (a);
}

t_num	*ft_sort(t_num *a, t_num **b)
{
	int to;
	int max;
	int z;
	int min;

	min = get_min(a);
	z = get_second_min(a, min);
	max = get_max(a);
	to = ft_direction(get_pos(a, z), get_pos(a, min), get_pos(a, max), get_struct_len(a));
	while (a->num != min && !stacks_is_sort(a, (*b)))
	{
		if (a->num == z && !stacks_is_sort(a, (*b)))
		{
			(*b) = ft_pb(&a, (*b));
			ft_print(a, (*b));
			break;
		}
		if (a->num == max && !stacks_is_sort(a, (*b)))
		{
			(*b) = ft_pb(&a, (*b));
			ft_print(a, (*b));
			(*b) = ft_rb((*b));
			ft_print(a, (*b));
			break;
		}
		a = step(to, min, a);
	}
	return (a);
}

t_num *ft_oper(t_num *a, t_num **b)
{
	int min;

	min = get_min(a);
	a = ft_sort(a, b);
	if (a->num == min && !stacks_is_sort(a, (*b)))
	{
		(*b) = ft_pb(&a, (*b));
		ft_print(a,(*b));
		if ((*b)->next && (*b)->num < (*b)->next->num)
		{
			(*b) = ft_sb((*b));
			ft_print(a,(*b));
		}
	}
	return (a);
}

t_num	*push_swap(t_num *a, t_num *b)
{
	t_num *q;
	int min;

	while (a->next != NULL && !stacks_is_sort(a, b))
	{
		if (!sort_one(&a, b))
			break ;
		min = get_min(a);
		a = ft_oper(a, &b);
	}
	return (ft_pushb_a(b, &a));
}

int			ft_is_number(char *num)
{
	int		i;

	i = 0;
	if (num[i] == '-')
		i++;
	while (num[i])
	{
		if (!(num[i] <= '9' && num[i] >= '0'))
			return (0);
		i++;
	}
	return (1);
}

int				ft_init_stack(t_num **stacks, int ac, char **av)
{
	int i;

	i = 0;
	while (++i < ac)
	{
		if (ft_is_number(av[i]))
			(*stacks)->num = ft_atoi(av[i]);
		else
			return (0);
		*stacks = (*stacks)->next;
	}
	return (1);
}

int main(int argc, char **argv)
{
	count = 0;
	int n[500];
	int i = 0;
	int j;

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

	a = lst_new(10);
//	if (ft_init_stack(&a, argc, argv) == 0)
//		ft_putstr_fd("Error\n", 2);
	while (i < 10)
	{
		a->num = n[i];
		printf("%d  ", a->num);
		a = a->next;
		i++;
	}
	printf("\n");
//	b = lst_new(0);
//	b = NULL;
	a = push_swap(a, b);
	ft_display_a(a);
	printf("(%d)", count);
	return 1;
}
