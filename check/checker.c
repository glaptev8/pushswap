/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmelia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 17:49:37 by tmelia            #+#    #+#             */
/*   Updated: 2019/11/15 17:49:39 by tmelia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		init_check(int *argc, char **argv, t_num **a, int *flag)
{
	if (!argv[0])
		return (0);
	if (argv && *argv && argv[0][0] == '\0')
		return (0);
	if (*argc == 0 || (*argc == 1 && !ft_strcmp(argv[0], "-v")))
		return (0);
	if (!ft_strcmp(argv[0], "-v"))
	{
		*flag = 1;
		(*argc)--;
		argv++;
	}
	if (argv && *argv && argv[0][0] == '\0')
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	*a = lst_new(*argc);
	if (ft_init_stack(a, *argc, argv) == 0)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	return (1);
}

int		check_step(char *com, t_num **a, t_num **b)
{
	if (!ft_strcmp(com, "sa"))
		*a = ft_sa(*a);
	else if (!ft_strcmp(com, "sb"))
	{
		if (*b)
			*b = ft_sb(*b);
	}
	else if (!ft_strcmp(com, "ra"))
		*a = ft_ra(*a);
	else if (!ft_strcmp(com, "rb"))
		*b = ft_rb(*b);
	else if (!ft_strcmp(com, "rra"))
		*a = ft_rra(*a);
	else if (!ft_strcmp(com, "rrb"))
		*b = ft_rrb(*b);
	else
		return (0);
	return (1);
}

int		check_step2(char *com, t_num **a, t_num **b)
{
	if (!ft_strcmp(com, "pb"))
	{
		if (*a && (*a)->next && (*a)->next != *a)
			(*b) = ft_pb(a, (*b));
		else if ((*a))
		{
			(*b) = lst_add((*b), (*a)->num);
			free((*a));
			(*a) = NULL;
		}
	}
	else if (!ft_strcmp(com, "pa"))
	{
		if ((*b) && (*b)->next && (*b)->next != (*b))
			(*a) = ft_pa((*a), b);
		else if ((*b))
		{
			(*a) = lst_add((*a), (*b)->num);
			free((*b));
			(*b) = NULL;
		}
	}
	else
		return (0);
	return (1);
}

int		check_step3(char *com, t_num **a, t_num **b)
{
	if (!ft_strcmp(com, "rrr"))
		ft_rrr(a, b);
	else if (!ft_strcmp(com, "rr"))
		ft_rr(a, b);
	else
	{
		ft_putstr_fd("Error\n", 2);
		free(com);
		return (-1);
	}
	return (1);
}

int		main(int argc, char **argv)
{
	t_num	*a;
	t_num	*b;
	char	*com;
	int		flag;
	char	**s;

	argv++;
	flag = 0;
	com = NULL;
	b = NULL;
	s = check_str(&argc, &argv);
	if (s && !ft_strcmp(argv[0], "-v"))
		flag = 1;
	if (argc == 2 && !ft_strcmp(argv[0], "-v") && !s)
		return (0);
	if (valid_check(s ? s : argv, &argc, &flag, &a) == 0)
	{
		finish_check(&a, &b, s);
		return (0);
	}
	if (ft_check_step(com, &a, &b, flag) == 0)
	{
		finish_check(&a, &b, s);
		return (0);
	}
	finish_check(&a, &b, s);
	return (0);
}
