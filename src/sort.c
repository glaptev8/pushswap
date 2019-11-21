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
		return (i);
	a = a->next;
	while (a != q)
	{
		i++;
		if (a->num <= n)
			return (i);
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
	a = a->prev;
	i++;
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
		return (i);
	a = a->next;
	while (a != q)
	{
		i++;
		if (a->num >= n)
			return (i);
		a = a->next;
	}
	return (i);
}

int		get_prev2(t_num *a, int n)
{
	int i;
	t_num *q;

	q = a;
	i = 0;
	if (a->num >= n)
		return (i);
	a = a->prev;
	while (a != q)
	{
		i++;
		if (a->num >= n)
			return (get_struct_len(a) - i);
		a = a->prev;
	}
	return (get_struct_len(a) - i);
}

void	ft_sort(t_num **a, t_num **b)
{
	int max;
	int z;
	int min;
	int average[12];
	int len;
	len = get_struct_len(*a) + 1;
	min = get_min(*a) - 1;
	ft_init_average(a, len, min, average);
	while ((*a) && (*a)->next && *a != (*a)->next)
	{
		if (more_average(*a, average[0], min))
			while_more_average (a, b, average[0], average[10]);
					*b = ft_pb(a, *b);
	}
	min = get_min(*b);
	ft_init_average(b, get_struct_len(*b) + 1, get_min(*b) - 1, average);
	while ((*b))
	{
		min = get_min(*b);
		if (more_average2(*b, average[4], average[8]))
		{
			while_more_average2(a, b, average[4], average[8]);
		}
		if (more_average2(*b, average[0], average[9]))
		{
			while_more_average2 (a, b, average[0], average[9]);
		}
		else if (more_average2(*b, average[5], average[0]))
		{
			while_more_average2(a, b, average[5], average[0]);
		}
		else if (more_average2(*b, average[1], average[10]))
		{
			while_more_average2(a, b, average[1], average[10]);
		}
		else if (more_average2(*b, average[6], average[11]))
		{
			while_more_average2(a, b, average[6], average[11]);
		}
		else if (more_average2(*b, average[2], average[7]))
		{
			while_more_average2(a, b, average[2], average[7]);
		}
		else if (more_average2(*b, average[4], get_max(*b)))
		{
			while_more_average2(a, b, average[4], get_max(*b));
		}
		else
			*a = ft_pa(*a, b);
	}
	ft_init_average(a, get_struct_len(*a) + 1, get_min(*a) - 1, average);
	min = get_min(*a) - 1;
	max = get_max(*a);
	while ((*a) && (*a)->next && *a != (*a)->next)
	{
		if (more_average(*a, average[3], min))
		{
			while_more_average (a, b, average[3], min);
			min = get_min(*b);
		}
		else if (more_average(*a, average[11], min))
		{
			while_more_average (a, b, average[11], average[2]);
			min = get_min(*b);
		}
		else if (more_average(*a, average[10], min))
		{
			while_more_average (a, b, average[10], average[6]);
			min = get_min(*b);
		}
		else if (more_average(*a, average[0], min))
		{
			while_more_average (a, b, average[0], average[5]);
			min = get_min(*b);
		}
		else if (more_average(*a, average[4], min))
		{
			while_more_average (a, b, average[4], average[9]);
			min = get_min(*b);
		}
		else if (more_average(*a, average[8], min))
		{
			while_more_average (a, b, average[8], average[4]);
			min = get_min(*b);
		}
		else if (more_average(*a, average[4], min))
		{
			while_more_average (a, b, average[4], min);
		}
		*b = ft_pb(a, *b);
		if (*b && (*b)->num)
			min = get_min(*b);
	}
	if ((*a) && (*a)->next && a == (*a)->next)
		*b = ft_pb(a, *b);
}

void	ft_oper(t_num **a, t_num **b)
{
	int	min;
	ft_sort(a, b);
}
