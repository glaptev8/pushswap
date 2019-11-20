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

	if (m > d)
		to = y - m <= d ? 2 : 1;
	else
		to = y - d <= m ? 2 : 1;
	return (to);
}

void	ft_pushb_a(t_num **b, t_num **a)
{
	int		q;

	q = get_struct_len((*b));
	while (--q >= 0)
	{
		(*a) = ft_pa((*a), b);
		if (q >= -1)
		{
			if ((*b) && (*b)->prev &&
			(*b)->num > (*b)->prev->num && ((*b)->num > (*a)->prev->num))
				(*b) = ft_rrb((*b));
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
	(*a)->num > (*a)->next->num ? (*a) = ft_sa((*a)) : 0;
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
//	if (!sort_one(a, b))
//		return ;
//	while (!stack_a_sort(*a))
		ft_oper(a, &b);
//	if (!stacks_is_sort((*a), b) || b)
//		ft_pushb_a(&b, a);
}

int		main(int argc, char **argv)
{
	char	**s;
	t_num	*a;

	s = NULL;
	argc--;
	if (argc == 1)
	{
		s = ft_strsplit(argv[1], ' ');
		argc = 0;
		while (s[argc])
			argc++;
	}
	argv++;
	a = lst_new(argc);
	if (stack_push(&a, argc, s ? s : argv) == 0)
	{
		fresh(s);
		return (0);
	}
	push_swap(&a);
	clear(&a, argc);
	fresh(s);
	return (1);
}
