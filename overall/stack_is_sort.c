/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_is_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmelia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 17:37:17 by tmelia            #+#    #+#             */
/*   Updated: 2019/11/15 17:37:19 by tmelia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		stacks_is_sort(t_num *a, t_num *b)
{
	int		ferst_a;

	if (!a || !a->next)
		return (1);
	ferst_a = a->num;
	while (a->num < a->next->num)
		a = a->next;
	if (a->next->num != ferst_a)
		return (0);
	if (!b || !b->next)
		return (1);
	if (ferst_a < b->num)
		return (0);
	return (1);
}
