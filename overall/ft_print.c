/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmelia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 17:36:46 by tmelia            #+#    #+#             */
/*   Updated: 2019/11/15 17:36:47 by tmelia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		init_printf(t_num **a, t_num **b, int *o)
{
	int d;

	d = 0;
	write(1, "\e[1;1H\e[2J", 11);
	ft_printf("%-13s stack2\n", "stack1");
	if (*a)
	{
		*o = (*a)->num;
		ft_printf("%-14d", *o);
	}
	else
		ft_printf("              ");
	if (*a && (*a)->next)
		*a = (*a)->next;
	if (*b)
	{
		d = (*b)->num;
		ft_printf("%d", d);
		if ((*b)->next)
			*b = (*b)->next;
	}
	ft_printf("\n");
	return (d);
}

void	ft_print(t_num *a, t_num *b)
{
	int o;
	int d;

	d = init_printf(&a, &b, &o);
	while ((a && a->num != o) || (b && b->next && b->num != d))
	{
		if (a && a->num != o && a->next)
		{
			ft_printf("%-14d", a->num);
			a = a->next;
		}
		else
			ft_printf("              ");
		if (b && b->index == -1 && b->next && b->num != d)
			ft_printf("%d", b->num);
		if (b && b->next && b->num != d)
			b = b->next;
		ft_printf("\n");
	}
	ft_printf("---------------------------------\n");
}
