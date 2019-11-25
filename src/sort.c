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

void	sort_three(t_num **a)
{
	int i;

	i = 0;
	while (i < 2)
	{
		if ((*a)->num > (*a)->prev->num)
			(*a) = ft_ra(*a);
		else if ((*a)->num > (*a)->next->num)
			(*a) = ft_sa(*a);
		else if ((*a)->prev->num < (*a)->next->num)
			(*a) = ft_rra(*a);
		i++;
	}
}

void	sort_five(t_num **a, t_num **b)
{
	int to;
	int max;
	int min;

	max = get_max(*a);
	min = get_min(*a);
	to = ft_direction(1, get_pos(*a, max), get_pos(*a, min), 5);
	while (get_struct_len(*a) + 1 > 3)
	{
		if ((*a)->num == min || (*a)->num == max)
			*b = ft_pb(a, *b);
		else
			*a = (to == 1) ? ft_rra(*a) : ft_ra(*a);
	}
	sort_three(a);
	*a = ft_pa(*a, b);
	if ((*a)->num > (*a)->prev->num)
	{
		*a = ft_ra(*a);
		*a = ft_pa(*a, b);
	}
	else
	{
		*a = ft_pa(*a, b);
		*a = ft_ra(*a);
	}
}

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

int		init_n(int *min, int *z, int *max, t_num **a)
{
	*min = get_min((*a));
	*z = get_second_min((*a), *min);
	*max = get_max((*a));
	return (ft_direction(get_pos((*a), *z), get_pos((*a), *min),
			get_pos((*a), *max), get_struct_len((*a))));
}

void	ft_sort(t_num **a, t_num **b)
{
	int average[9];

	if (*a && get_struct_len(*a) <= 100)
		push_last_a(a, b, average);
	else
	{
		while (*a != (*a)->next)
		{
			ft_init_average(*a, get_min(*a) - 1, average, 1);
			if (more_average(*a, average[1], get_min(*a) - 1))
				while_more_average(a, b, average[0], average[1]);
			else
				*b = ft_pb(a, *b);
		}
		step_for_b(a, b, average);
		while (*a != (*a)->next)
			step_for_a(a, b, average);
	}
	ft_pushb_a(a, b);
}
