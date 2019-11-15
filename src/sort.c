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

void	ft_sort(t_num **a, t_num **b)
{
	int to;
	int max;
	int z;
	int min;

	to = init_n(&min, &z, &max, a);
	while ((*a)->num != min && !stacks_is_sort((*a), (*b)))
	{
		if (!sort_one(a, (*b)))
			break ;
		if ((*b) && (*a)->num == z && !stacks_is_sort((*a), (*b)))
		{
			(*b) = ft_pb(a, (*b));
			break ;
		}
		if ((*b) && get_struct_len((*b)) + 1 > 2 && (*a) &&
		(*a)->num && (*a)->num == max && !stacks_is_sort((*a), (*b)))
		{
			(*b) = ft_pb(a, (*b));
			(*b) = ft_rb((*b));
			break ;
		}
		step(to, min, a);
	}
}

void	ft_oper(t_num **a, t_num **b)
{
	int	min;

	min = get_min((*a));
	ft_sort(a, b);
	if ((*a)->next != (*a) && (*a)->num == min && !stacks_is_sort((*a), (*b)))
	{
		(*b) = ft_pb(a, (*b));
		if ((*a) && (*a)->num && (*a)->next &&
		(*a)->next->num && (*a)->num > (*a)->next->num)
			(*a) = ft_sa((*a));
		if ((*b) && (*b)->next &&
		(*b)->next != (*b) && (*b)->num < (*b)->next->num)
			(*b) = ft_sb((*b));
	}
}
