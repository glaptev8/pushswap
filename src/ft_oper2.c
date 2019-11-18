/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_oper2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmelia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 17:34:39 by tmelia            #+#    #+#             */
/*   Updated: 2019/11/15 17:34:41 by tmelia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_num		*ft_rrb(t_num *b)
{
	if (b && b->prev && b->prev != b)
	{
		ft_printf("rrb\n");
		b = b->prev;
	}
	return (b);
}

t_num		*ft_pb(t_num **a, t_num *b)
{
	ft_printf("pb\n");
	b = lst_add(b, (*a)->num);
	if ((*a) && (*a)->next && (*a) != (*a)->next)
		lst_remove(a);
	return (b);
}

t_num		*ft_pa(t_num *a, t_num **b)
{
	ft_printf("pa\n");
	a = lst_add(a, (*b)->num);
	if ((*b) && (*b)->next && (*b)->next != *b)
		lst_remove(b);
	else
	{
		free(*b);
		*b = NULL;
//		free(b);
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
