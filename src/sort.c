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
	a = a->next;
	while (a->num > n && a != q)
	{
		i++;
		a = a->prev;
	}
	return (i);
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
	i = 0;
	to = init_n(&min, &z, &max, a);
	len = get_struct_len(*a) + 1;
	min = get_min(*a) - 1;
//	average = ft_average((*a), len);
	average = ft_average((*a), len, min);
	average2 = ft_average2((*a), len, average);
	average3 = ft_average2((*a), len, average2);
	while (*a != (*a)->next)
	{
//		if (more_average(*a, average, min) == 0)
//		{
		average = ft_average((*a), len, min);
		average2 = ft_average2((*a), len, average);
		average3 = ft_average2((*a), len, average2);
//		}
		if (more_average(*a, average3, min) == 0)
		{
			while (more_average(*a, average2, min))
			{
				if ((*a)->num <= average2 && (*a)->num > min && (*a)->num != max)
					*b = ft_pb(a, *b);
				else
					*a = ft_ra(*a);
			}
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
		while (more_average(*a, average3, min))
		{
			next = get_next(*a, average3);
			prev = get_prev(*a, average3);
			to = ft_direction(1, get_pos(*a, next), get_pos(*a, prev), get_struct_len(*a));
			if ((*a)->num <= average2 && (*a)->num > min && (*a)->num != max)
			{
				*b = ft_pb(a, *b);
				if ((*b)->next && (*b) != (*b)->next && (*b)->num <= average3)
					*b = ft_rb(*b);
				else if ((*b)->next && (*b) != (*b)->next && (*b)->num < (*b)->next->num)
						(*b) = ft_sb(*b);
				to = ft_direction(1, get_pos(*a, next), get_pos(*a, prev), get_struct_len(*a));
			}
			else if (to == 2)
				*a = ft_rra(*a);
			else
				*a = ft_ra(*a);
		}
		min = get_min(*b);
	}
	min = 0;
	while (*b != (*b)->next)
	{
		max = get_max(*b);
		z = get_second_max(*b, max);
//		to = ft_direction(1, get_pos(*b, max), get_pos(*b, z), get_struct_len(*b));
		if (get_pos(*b, max) > get_struct_len(*b) / 2)
			to = 2;
		else
			to = 1;
//		z = get_pos(*b, max);
//		to = ft_direction(1, 1, z, get_struct_len(*b) + 1);
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
//	ft_print(*a, *b);
}

void	ft_oper(t_num **a, t_num **b)
{
	int	min;

	min = get_min((*a));
	ft_sort(a, b);
//	if ((*a)->next != (*a) && (*a)->num == min && !stacks_is_sort((*a), (*b)))
//	{
//		(*b) = ft_pb(a, (*b));
//		if ((*a) && (*a)->num && (*a)->next &&
//		(*a)->next->num && (*a)->num > (*a)->next->num)
//			(*a) = ft_sa((*a));
//		if ((*b) && (*b)->next &&
//		(*b)->next != (*b) && (*b)->num < (*b)->next->num)
//			(*b) = ft_sb((*b));
//	}
}
