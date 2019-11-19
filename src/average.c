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