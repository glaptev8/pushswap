#include "../includes/push_swap.h"

int		get_next(t_num *a, int n)
{
	int i;
	t_num *q;

	q = a;
	i = 0;
	if (a->num <= n)
		return (1);
	a = a->next;
	while (a->num > n && a != q)
	{
		i++;
		a = a->next;
	}
	return (i);
}

int		get_prev(t_num *a, int n)
{
	int i;
	t_num *q;

	i = 0;
	q = a;
	i = 0;
	if (a->num <= n)
		return (1);
	a = a->prev;
	while (a->num > n && a != q)
	{
		i++;
		a = a->prev;
	}
	return (get_struct_len(a) - i);
}

int		get_next2(t_num *a, int n)
{
	int i;
	t_num *q;

	q = a;
	i = 0;
	if (a->num >= n)
		return (1);
	a = a->next;
	while (a->num < n && a != q)
	{
		i++;
		a = a->next;
	}
	return (i);
}


int		get_prev2(t_num *a, int n)
{
	int i;
	t_num *q;

	i = 0;
	q = a;
	i = 0;
	if (a->num >= n)
		return (1);
	a = a->prev;
	while (a->num < n && a != q)
	{
		i++;
		a = a->prev;
	}
	return (get_struct_len(a) - i);
}