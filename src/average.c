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
	if (count == 0)
		return (0);
	return (average / count);
}

int		ft_2average(t_num *a, int len, int min, int max)
{
	int average;
	int i;
	int count;

	count = 0;
	i = 0;
	average = 0;
	while (i < len)
	{
		if (a->num && a->num > min && a->num <= max)
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

int		ft_2average2(t_num *a, int len, int min, int max)
{
	int average;
	int i;
	int count;

	count = 0;
	i = 0;
	average = 0;
	while (i < len)
	{
		if (a->num && a->num >= min && a->num <= max)
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

int		more_average2(t_num *a, int n, int min)
{
	t_num *b;

	if (!a)
		return (0);
	if (a->num > n)
		return (1);
	b = a;
	a = a->next;
	while (a != b)
	{
		if (a->num > n)
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

void	while_more_average(t_num **a, t_num **b, int average, int average2)
{
	int min;
	int max;
	int next;
	int prev;
	int to;
	static count = 0;
	to = ft_direction(1, get_pos(*a, next), get_pos(*a, prev), get_struct_len(*a));
	max = get_max(*a);
	if (*b && (*b)->num)
		min = get_min(*b);
	else
		min = get_min(*a) - 1;
	while (more_average(*a, average, min))
	{
		next = get_next(*a, average);
		prev = get_prev(*a, average);
		if ((*a)->num <= average && (*a)->num > min && (*a)->num != max)
		{
			*b = ft_pb(a, *b);
//			if ((*b)->next && (*b) != (*b)->next && (*b)->num <= average2)
//				*b = ft_rb(*b);
			to = ft_direction(1, get_pos(*a, next), get_pos(*a, prev), get_struct_len(*a));
		}
		else if (to == 1)
			*a = ft_ra(*a);
		else
			*a = ft_rra(*a);
		count++;
	}
}

void	while_more_average2(t_num **a, t_num **b, int average, int average2)
{
	int min;
	int max;
	int next;
	int prev;
	int to;
	static count = 0;
	to = ft_direction(1, get_pos(*b, next), get_pos(*b, prev), get_struct_len(*b));
	max = get_max(*b);
	if (*b && (*b)->num)
		min = get_min(*b);
	else
		min = get_min(*b) - 1;
	while (more_average2(*b, average, min))
	{
//		printf("%d", average);
		next = get_next2(*b, average);
		prev = get_prev2(*b, average);
		if ((*b)->num >= average)
		{
			*a = ft_pa(*a, b);
			if ((*a)->next && (*a) != (*a)->next && (*a)->num > average2)
				*a = ft_ra(*a);
			to = ft_direction(1, get_pos(*b, next), get_pos(*b, prev), get_struct_len(*b));
		}
		else if (to == 1)
			*b = ft_rb(*b);
		else
			*b = ft_rrb(*b);
		count++;
	}
}
void	ft_init_average(t_num **a, int len, int min, int *average)
{
	average[0] = ft_average((*a), len, min);
	average[1] = ft_average2((*a), len, average[0]);
	average[2] = ft_average2((*a), len, average[1]);
	average[3] = ft_average2((*a), len, average[2]);
	average[4] = ft_2average((*a), len, average[0], get_max(*a));
	average[5] = ft_2average2((*a), len, average[1], average[4]);
	average[6] = ft_2average2((*a), len, average[2], average[5]);
	average[7] = ft_2average2((*a), len, average[3], average[6]);
}