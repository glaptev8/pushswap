/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmelia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 19:22:45 by tmelia            #+#    #+#             */
/*   Updated: 2019/11/15 19:22:47 by tmelia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_num		*ft_rrb(t_num *b)
{
	if (b && b->prev && b->prev != b)
		b = b->prev;
	return (b);
}

t_num		*ft_pb(t_num **a, t_num *b)
{
	if ((*a))
	{
		b = lst_add(b, (*a)->num);
		if ((*a) && (*a)->next && (*a) != (*a)->next)
			lst_remove(a);
	}
	return (b);
}

t_num		*ft_pa(t_num *a, t_num **b)
{
	if (b)
	{
		a = lst_add(a, (*b)->num);
		if ((*b)->next)
			lst_remove(b);
	}
	return (a);
}

void		ft_rrr(t_num **a, t_num **b)
{
	(*a) = ft_rra((*a));
	(*b) = ft_rrb((*b));
}

void		ft_rr(t_num **a, t_num **b)
{
	(*a) = ft_ra((*a));
	(*b) = ft_ra((*b));
}
