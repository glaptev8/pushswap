/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmelia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 17:49:50 by tmelia            #+#    #+#             */
/*   Updated: 2019/11/15 17:49:51 by tmelia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_num		*ft_sa(t_num *a)
{
	int num;

	if (a && a->next && a != a->next)
	{
		num = a->num;
		a->num = a->next->num;
		a->next->num = num;
	}
	return (a);
}

t_num		*ft_sb(t_num *b)
{
	int num;

	if (b && b->next && b->next != b)
	{
		num = b->num;
		b->num = b->next->num;
		b->next->num = num;
	}
	return (b);
}

t_num		*ft_ra(t_num *a)
{
	if (a && a->next && a->next != a)
		a = a->next;
	return (a);
}

t_num		*ft_rb(t_num *b)
{
	if (b && b->next && b->next != b)
		b = b->next;
	return (b);
}

t_num		*ft_rra(t_num *a)
{
	if (a && a->prev && a->prev != a)
		a = a->prev;
	return (a);
}
