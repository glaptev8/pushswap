/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmelia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 17:17:37 by tmelia            #+#    #+#             */
/*   Updated: 2019/11/15 17:17:39 by tmelia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		sort_one(t_num **a, t_num *b)
{
	if (stacks_is_sort((*a)->next, b))
	{
		(*a) = ft_ra((*a));
		return (0);
	}
	if (stacks_is_sort((*a)->prev, b))
	{
		(*a) = ft_rra((*a));
		return (0);
	}
	return (1);
}

void	step(int to, int min, t_num **a)
{
	if (to == 1 && (*a)->num != min)
		(*a) = ft_ra((*a));
	else if ((*a)->num != min)
		(*a) = ft_rra((*a));
}

int		init_n(int *min, int *z, int *max, t_num **a)
{
	*min = get_min((*a));
	*z = get_second_min((*a), *min);
	*max = get_max((*a));
	return (ft_direction(get_pos((*a), *z), get_pos((*a), *min),
			get_pos((*a), *max), get_struct_len((*a))));
}

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

void	ft_sort(t_num **a, t_num **b)
{
	int to;
	 int max;
	int z;
	int min;
	int average;
	int len;
	int i;
	int next;
	int prev;
	int average2;
	int average3;
	int average4;
	int average5;
	i = 0;
	to = init_n(&min, &z, &max, a);
	len = get_struct_len(*a) + 1;
	min = get_min(*a) - 1;

	average = ft_average((*a), len, min);
	average2 = ft_average2((*a), len, average);
	while (*a != (*a)->next)
	{
		if (more_average(*a, average2, min))
			while_more_average(a, b, average, average2);
		else
			*b = ft_pb(a, *b);
	}
	if (*a && (*a)->next && (*a) == (*a)->next)
		*b = ft_pb(a, *b);
	while ((*b) && (*b)->next && *b != (*b)->next)
	{
		average = ft_average((*b), len, min);
		average2 = ft_average((*b), len, average);
		average3 = ft_average((*b), len, average2);
		average4 = ft_average((*b), len, average3);
		average5 = ft_average((*b), len, average4);
		if (get_struct_len(*b) > 50)
		{
			if (more_average2(*b, average5, min) == 0)
			{
				while_more_average2 (a, b, average3, average4);
			}
			if (more_average2(*b, average4, min) == 0)
			{
				while_more_average2 (a, b, average2, average3);
			}
			if (more_average2(*b, average3, min) == 0)
			{
				while_more_average2 (a, b, average, average2);
			}
			while_more_average2 (a, b, average4, average5);
		}
		if (more_average2(*b, average2, min) == 0)
		{
			while (more_average(*b, average, min))
			{
				if ((*b)->num <= average)
					*a = ft_pa(*a, b);
				else
					*b = ft_rb(*b);
			}
		}
		if ((*b) && more_average2(*b, average2, min) == 0)
		{
			while (more_average2(*b, average, min))
			{
				if ((*b)->num >= average && (*b)->num > min && (*b)->num != max)
					*a = ft_pa(*a, b);
				else
					*b = ft_rb(*b);
			}
		}
		if ((*b) && get_struct_len(*b) <= 50)
		{
			while_more_average2 (a, b, average, average2);
		}
	}

	while (*a != (*a)->next)
	{
		average = ft_average((*a), len, min);
		average2 = ft_average2((*a), len, average);
		average3 = ft_average2((*a), len, average2);
		average4 = ft_average2((*a), len, average3);
		average5 = ft_average2((*a), len, average4);
		if (get_struct_len(*a) > 50)
		{
			if (more_average(*a, average5, min) == 0)
			{
				while_more_average (a, b, average3, average4);
			}
			if (more_average(*a, average4, min) == 0)
			{
				while_more_average (a, b, average2, average3);
			}
			if (more_average(*a, average3, min) == 0)
			{
				while_more_average (a, b, average, average2);
			}
			while_more_average (a, b, average4, average5);
		}
		if (more_average(*a, average2, min) == 0)
		{
			while (more_average(*a, average, min))
			{
				if ((*a)->num <= average && (*a)->num > min && (*a)->num != max)
					*b = ft_pb(a, *b);
				else
					*a = ft_ra(*a);
			}
		}
		if (get_struct_len(*a) <= 50)
		{
			while_more_average (a, b, average, average2);

		}
		min = get_min(*b);
	}
	min = 0;
	while (*b != (*b)->next)
	{
		max = get_max(*b);
		z = get_second_max(*b, max);
		if (get_pos(*b, max) > get_struct_len(*b) / 2)
			to = 2;
		else
			to = 1;
		if ((*b)->num == max)
		{
			*a = ft_pa(*a, b);
			if ((*a)->num > (*a)->next->num)
				(*a) = ft_sa(*a);
			min = 0;
		}
		else if ((*b)->num == z && min == 0)
		{
			*a = ft_pa(*a, b);
			min = 1;
		}
		else if (to == 1)
			*b = ft_rb(*b);
		else if (to == 2)
			*b = ft_rrb(*b);
	}
	*a = ft_pa(*a, b);
	if ((*a)->num > (*a)->next->num)
		*a = ft_sa(*a);
}

void	ft_oper(t_num **a, t_num **b)
{
	int	min;

	min = get_min((*a));
	ft_sort(a, b);
}
