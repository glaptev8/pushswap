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
	int average;
	int len;
	int i;

	i = 0;
	to = init_n(&min, &z, &max, a);
	len = get_struct_len(*a) + 1;
	min = get_min(*a) - 1;
//	average = ft_average((*a), len);

	while (biger_min((*a), min) > 2)
	{
		average = ft_average((*a), len, min);
		while (more_average(*a, average, min))
		{
			if ((*a)->num < average && (*a)->num > min)
			{
				*b = ft_pb(a, *b);
//				ft_print(*a, *b);
				if ((*b)->prev && (*b) != (*b)->prev && (*b)->num > (*b)->prev->num)
					*b = ft_rrb(*b);
//				else if ((*b) && (*b)->next && (*b)->num > (*b)->next->num)
//					*b = ft_sb(*b);
			}
//			else if ((*a)->num > (*a)->next->num && (*a)->next->num > average && (*a)->num > min)
//				(*a) = ft_sa(*a);
			else
				*a = ft_ra(*a);
//			ft_print(*a, *b);
		}
//		printf("\n1111111111111111111111111111111111111111111    %d   %d", min, get_min(*b) - 1);
		if (has_nubmer(*a, min))
		{
			while ((*a)->prev->num != min)
			{
//				if ((*a)->num > (*a)->next->num && (*a)->next->num > average)
//					(*a) = ft_sa(*a);
//				else
					*a = ft_rra(*a);
			}
		}
		if (*b && !(*b)->next)
			(*a) = ft_pa(*a, b);
		while (*b && (*b)->next)
		{
//			ft_print(*a, *b);
			min = get_min(*b);
			max = get_max(*b);
			z = get_second_min(*a, min);
			to = ft_direction(z, get_pos(*b, min), get_pos(*b, max), get_struct_len(*b));
			if ((*b)->num == min)
			{
				*a = ft_pa(*a, b);
				*a = ft_ra(*a);
			}
			else if ((*b)->num == max)
			{
				*a = ft_pa(*a, b);
			}
			else if (to == 2)
				*b = ft_rrb(*b);
			else
				*b = ft_rb(*b);
//			ft_print(*a, *b);
		}
		while ((*a)->num <= average && (*a)->num != get_min(*a))
		{
			min = (*a)->num;
			*a = ft_ra(*a);
//			ft_print(*a, *b);
		}
//		ft_print(*a, *b);
	}
	if (biger_min((*a), min) == 2)
	{
		if ((*a)->num > (*a)->next->num)
			(*a) = ft_sa(*a);
		(*a) = ft_ra(*a);
		(*a) = ft_ra(*a);
	}
	else if (biger_min((*a), min) == 1)
		(*a) = ft_ra(*a);
//	*a = ft_ra(*a);
//	*a = ft_ra(*a);
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
