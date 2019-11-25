/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmelia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 13:56:10 by tmelia            #+#    #+#             */
/*   Updated: 2019/11/25 13:56:12 by tmelia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		is_a_sort(t_num *a)
{
	t_num *b;

	b = a;
	if (a && a->next && a->next == a)
		return (1);
	while (a && a->next && a->next != b)
	{
		if (a->num > a->next->num)
			return (0);
		a = a->next;
	}
	return (1);
}
