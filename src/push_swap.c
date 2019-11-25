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

int		ft_direction(int x, int d, int m, int y)
{
	int to;

	x = 1;
	if (m > d)
		to = y - m <= d ? 2 : 1;
	else
		to = y - d <= m ? 2 : 1;
	return (to);
}

void	ft_pushb_a(t_num **a, t_num **b)
{
	int z;
	int to;
	int flag;

	flag = 0;
	while (*b != (*b)->next)
	{
		z = get_second_max(*b, get_max(*b));
		to = (get_pos(*b, get_max(*b)) > get_struct_len(*b) / 2) ? 2 : 1;
		if ((*b)->num == get_max(*b))
		{
			*a = ft_pa(*a, b);
			((*a)->num > (*a)->next->num) ? (*a) = ft_sa(*a) : 0;
			flag = 0;
		}
		else if ((*b)->num == z && flag == 0)
		{
			*a = ft_pa(*a, b);
			flag = 1;
		}
		else
			*b = (to == 1) ? ft_rb(*b) : ft_rrb(*b);
	}
	*a = ft_pa(*a, b);
	((*a)->num > (*a)->next->num) ? *a = ft_sa(*a) : 0;
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
	t_num	*b;
	int		i;

	b = NULL;
	i = 0;
	if (!sort_one(a, b))
		return ;
	if (get_struct_len(*a) + 1 == 3)
	{
		sort_three(a);
		return ;
	}
	if (get_struct_len(*a) + 1 == 5)
	{
		sort_five(a, &b);
		return ;
	}
	if (!is_a_sort(*a))
		ft_sort(a, &b);
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
	return (0);
}
