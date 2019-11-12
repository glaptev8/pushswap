#include "../includes/push_swap.h"

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
	q = NULL;
	return (m);
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

