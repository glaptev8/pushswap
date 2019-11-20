#include "../includes/push_swap.h"

int		ft_average(t_num *a, int len, int min)
{
	int average;
	int i;
	int count;

	count = 0;
	i = 0;
	average = 0;
	while (i < len)
	{
		if (a->num && a->num > min)
		{
			average += a->num;
			count++;
		}
		i++;
		if (a->next)
			a = a->next;
		else
			return (0);
	}
	return (average / count);
}

int		ft_average2(t_num *a, int len, int min)
{
	int average;
	int i;
	int count;

	count = 0;
	i = 0;
	average = 0;
	while (i < len)
	{
		if (a->num && a->num < min)
		{
			average += a->num;
			count++;
		}
		i++;
		if (a->next)
			a = a->next;
		else
			return (0);
	}
	if (count == 0)
		return (0);
	return (average / count);
}

int		more_average(t_num *a, int n, int min)
{
	t_num *b;

	if (!a)
		return (0);
	if (a->num <= n && a->num > min)
		return (1);
	b = a;
	a = a->next;
	while (a != b)
	{
		if (a->num <= n && a->num > min)
			return (1);
		a = a->next;
	}
	return (0);
}

int has_nubmer(t_num *a, int n)
{
	t_num *q;

	if (a)
	{
		if (a->num == n)
			return (1);
		q = a;
		a = a->next;
		while (a != q)
		{
			if (a->num == n)
				return (1);
			a = a->next;
		}
	}
	return (0);
}

int biger_min(t_num *a, int min)
{
	t_num *q;
	int count;

	count = 0;
	if (a->num > min)
		count++;
	q = a;
	a = a->next;
	while (a != q)
	{
		if (a->num > min)
			count++;
		a = a->next;
	}
	return (count);
}

while_more_average(t_num **a, t_num **b, int average, int average2)
{
	int min;
	int max;
	int next;
	int prev;
	int to;

	max = get_max(*a);
	if (*b)
		min = get_min(*b);
	else
		min = get_min(*a) - 1;
	while (more_average(*a, average2, min))
	{
		next = get_next(*a, average2);
		prev = get_prev(*a, average2);
		to = ft_direction(1, get_pos(*a, next), get_pos(*a, prev), get_struct_len(*a));
		if ((*a)->num <= average && (*a)->num > min && (*a)->num != max)
		{
			*b = ft_pb(a, *b);
			if ((*b)->next && (*b) != (*b)->next && (*b)->num <= average2)
				*b = ft_rb(*b);
			to = ft_direction(1, get_pos(*a, next), get_pos(*a, prev), get_struct_len(*a));
		}
		else if (to == 2)
			*a = ft_rra(*a);
		else
			*a = ft_ra(*a);
	}
}