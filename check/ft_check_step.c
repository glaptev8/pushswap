/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_step.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmelia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 19:09:57 by tmelia            #+#    #+#             */
/*   Updated: 2019/11/15 19:09:59 by tmelia           ###   ########.fr       */
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

int		ft_check_step(char *com, t_num **a, t_num **b, int flag)
{
	flag == 1 ? ft_print(*a, *b) : 0;
	while (get_next_line(0, &com) != 0)
	{
		if (check_step(com, a, b) == 0)
			if (check_step2(com, a, b) == 0)
				if (check_step3(com, a, b) == -1)
					return (0);
		if (flag == 1)
			ft_print(*a, *b);
		free(com);
	}
	if (is_a_sort(*a) && !(*b))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (1);
}
