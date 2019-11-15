/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmelia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 17:17:26 by tmelia            #+#    #+#             */
/*   Updated: 2019/11/15 17:17:29 by tmelia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdlib.h>

int		ft_direction(int x, int d, int m, int y)
{
	int to;

	if (x > d && x > m)
		m < d ? d = m : 0;
	else if (d > x && d > m)
		m < x ? x = m : 0;
	else if (m > d && m > x)
	{
		if (d < x)
			x = m;
		else
			d = m;
	}
	if (x > d)
		to = y - x < d ? 2 : 1;
	else if (y - d <= x - 1 || d == y)
		to = 2;
	else
		to = 1;
	return (to);
}

void	ft_pushb_a(t_num **b, t_num **a)
{
	int		q;

	q = get_struct_len((*b));
	while (--q >= 0)
	{
		(*a) = ft_pa((*a), b);
		if (q >= 0)
		{
			if ((*b) && (*b)->prev &&
			(*b)->num > (*b)->prev->num && ((*b)->num > (*a)->prev->num))
				(*b) = (*b)->prev;
		}
		if ((*a)->num > (*a)->prev->num)
			(*a) = ft_ra((*a));
		if ((*a)->num > (*a)->next->num)
			(*a) = ft_sa((*a));
	}
	(*a) = lst_add((*a), (*b)->num);
	ft_printf("pa\n");
	if ((*a)->num > (*a)->prev->num)
		(*a) = ft_ra((*a));
	if ((*a)->num > (*a)->next->num)
		(*a) = ft_sa((*a));
	free(*b);
	b = NULL;
	free(b);
}

void	ft_display_a(t_num *a)
{
	int d;

	d = a->num;
	ft_printf("%d ", a->num);
	a = a->next ? a->next : a;
	while (a->next && a->num != d)
	{
		ft_printf("%d ", a->num);
		a = a->next;
	}
	ft_printf("\n");
}

void	push_swap(t_num **a)
{
	t_num *b;

	b = NULL;
	if ((*a) && (*a)->num && (*a)->next &&
	(*a)->next->num && (*a)->num > (*a)->next->num)
		*a = ft_sa(*a);
	if (!sort_one(a, b))
		return ;
	while ((*a) && (*a)->next && (*a)->next != (*a) && !stacks_is_sort((*a), b))
		ft_oper(a, &b);
	if (!stacks_is_sort((*a), b) || b)
		ft_pushb_a(&b, a);
}

int		main(int argc, char **argv)
{
	int		i;
	char	**s;
	t_num	*a;
	s = NULL;
	if (argc == 2)
	{
		s = ft_strsplit(argv[1], ' ');
		i = 0;
		while (s[i])
			i++;
		argc = i;
	}
	a = lst_new(argc);
	if (stack_push(&a, argc, s ? s : argv) == 0)
	{
		fresh(s);
		return (0);
	}
	push_swap(&a);
//	ft_display_a(a);
	clear(&a, argc);
	fresh(s);
	return (1);
}
