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
//	if (b->next)
//		return (0);
//	if (ferst_a < ferst_b)
//		return (0);
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
	{
		if (m < d)
			d = m;
	}
	else if (d > x && d > m)
	{
		if (m < x)
			x = m;
	}
	else if (m > d && m > x)
	{
		if (d < x)
			x = m;
		else
			d = m;
	}
	if (x > d)
	{
		if (y - x < d)
			to = 2;
		else
			to = 1;
	}
	else if (y - d <= x - 1 || d == y)
	{
		to = 2;
	}
	else
		to = 1;
	return (to);
}

void	push_swap(t_num *a, t_num *b)
{
	t_num *q;
	int d;
	int min;
	int x;
	int y;
	int z;
	int i;
	int to;
	int max;
	int m;

	i = 0;
	while (a->next != NULL && !stacks_is_sort(a, b))
	{
		if (stacks_is_sort(a->next, b))
		{
			a = ft_ra(a);
			ft_print(a, b);
			break;
		}
		q = a->next;
		min = a->num;
		max = a->num;
		z = min;
		x = 0;
		y = 0;
		d = 0;
		while (q != a)
		{
			y++;
			if (q->num < min)
			{
				z = min;
				x = d;
				d = y;
				min = q->num;
			}
			if (q->num < z && q->num != min)
			{
				z = q->num;
				x = y;
			}
			if (q->num > max)
			{
				m = y;
				max = q->num;
			}
			q = q->next;
		}
		to = ft_direction(x, d, m, y);
		i++;
		while (a->num != min && !stacks_is_sort(a, b))
		{
			if (a->num == z && !stacks_is_sort(a, b))
			{
				b = ft_pb(&a, b);
				ft_print(a, b);
				break;
			}
			if (a->num == max && !stacks_is_sort(a, b))
			{
				b = ft_pb(&a, b);
				ft_print(a, b);
				b = ft_rb(b);
				ft_print(a, b);
				break;
			}
			if (to == 1 && a->num != min)
			{
				a = ft_ra(a);
				ft_print(a, b);
			}
			else if (a->num != min)
			{
				a = ft_rra(a);
				ft_print(a, b);
			}
		}
		if (a->num == min && !stacks_is_sort(a, b))
		{
			b = ft_pb(&a, b);
			ft_print(a,b);
			if (b->next && b->num < b->next->num)
			{
				b = ft_sb(b);
				ft_print(a,b);
			}
		}
	}

	// нужно вывод
	if (b && b->index == -1)
	{
		while (b != NULL)
		{
			a = ft_pa(a, &b);
			ft_print(a, b);
			if (b && b->prev && b->num > b->prev->num)
			{
				b = ft_rrb(b);
				ft_print(a, b);
			}
			if (a->num > a->prev->num)
			{
				a = ft_ra(a);
				ft_print(a, b);
			}
			if (a->num > a->next->num)
			{
				a = ft_sa(a);
				ft_print(a, b);
			}
		}
	}
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
//	int n[5] = {1041, 863, 1080, 1069, 1004};
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

	a = lst_new(15);
//	if (ft_init_stack(&a, argc, argv) == 0)
//		ft_putstr_fd("Error\n", 2);
	while (i < 15)
	{
		a->num = n[i];
		printf("%d  ", a->num);
		a = a->next;
		i++;
	}
	printf("\n");
	b = lst_new(0);
	b = NULL;
//	ft_print(a, b);
	push_swap(a, b);
	printf("\n(%d)", count);
	return 1;
}
