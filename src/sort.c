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
	i++;
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
	i++;
	while (a->num > n && a != q)
	{
		i++;
		a = a->prev;
	}
	return (i);
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
	i++;
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
	a = a->next;
	i++;
	while (a->num < n && a != q)
	{
		i++;
		a = a->prev;
	}
	return (i);
}

void	ft_sort(t_num **a, t_num **b)
{
	int max;
	int z;
	int min;
	int average[8];
	int len;
	len = get_struct_len(*a) + 1;
	min = get_min(*a) - 1;
	ft_init_average(a, len, min, average);
	while ((*a) && (*a)->next && *a != (*a)->next)
	{
//		if (more_average(*a, average[2], min) == 0 && get_struct_len(*a) > 150)
//			ft_init_average(a, len, min, average);
//		else if (more_average(*a, average[1], min) == 0)
		if (more_average(*a, average[0], min))
			while_more_average (a, b, average[0], average[2]);
//		while_more_average (a, b, average[0], average[2]);
//			ft_init_average(a, len, min, average);
//		if (get_struct_len(*a) > 150)
//		{
//			while_more_average (a, b, average[1], average[2]);
//			if (more_average(*a, average[3], min) == 0)
//				while_more_average (a, b, average[0], average[1]);
//		}
//		if (get_struct_len(*a) > 50 && get_struct_len(*a) <= 150)
//		{
//			while_more_average (a, b, average[0], average[1]);
//			if (more_average(*a, average[2], min) == 0)
//				while_more_average (a, b, average[0], average[1]);
//		}
//		else if (get_struct_len(*a) <= 50)
//			while_more_average (a, b, average[0], average[1]);
//				if ((*a)->num >= average[0] && (*a)->num > min && (*a)->num != max)
					*b = ft_pb(a, *b);
//				else
//					*a = ft_ra(*a);
//			}
//		if (*b && (*b)->num)
//			min = get_min(*b);
	}
	min = get_min(*b);
	ft_init_average(b, get_struct_len(*b) + 1, get_min(*b) - 1, average);
//	printf("%d      %d   %d    %d    %d    %d %d", average[0], average[1], average[2], average[3], average[4],average[5], average[6]);
	while ((*b))
	{
		if (more_average2(*b, average[0], average[4]))
		{
			while_more_average2 (a, b, average[0], average[4]);
		}
		else if	(more_average2(*b, average[1], average[5]))
		{
			while_more_average2 (a, b, average[1], average[5]);
		}
		else if (more_average2(*b, average[2],average[6]))
		{
			min = get_min(*b);
			while_more_average2 (a, b, average[2], average[6]);
		}
		else
			*a = ft_pa(*a, b);
//		if (more_average2(*a, average[0], min) && more_average2(*a, average[2], min))

	}
//	*a = ft_pa(*a, b);
//	ft_print(*a, *b);
//	printf("(%d   %d  %d   %d)", average[0], average[1], average[2], average[3]);
//	printf("\n\n\n%d\n\n\n", counttt);
}

void	ft_oper(t_num **a, t_num **b)
{
	int	min;
	ft_sort(a, b);
}
