#include "../includes/push_swap.h"

int	init_check(int *argc, char **argv, t_num **a, int *flag)
{
	if (*argc == 1 || (*argc == 2 && !ft_strcmp(argv[1], "-v")))
		return (0);
	if (!ft_strcmp(argv[1], "-v"))
	{
		*flag = 1;
		(*argc)--;
		argv++;
	}
	*a = lst_new((*argc) - 1);
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
		{
			(*b) = ft_pb(a, (*b));
		}
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

int	main(int argc, char **argv)
{
	t_num *a;
	t_num *b;
	char *com;
	int flag = 0;

	if (init_check(&argc, argv, &a, &flag) == 0)
	{
		finish_check(&a, &b);
		return (0);
	}
	if (has_dublicat(argv, argc) == -1)
	{
		finish_check(&a, &b);
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	ft_print(a, b);
	while (get_next_line(0, &com) != 0)
	{
		if (check_step(com , &a, &b) == 0)
			if (check_step2(com , &a, &b) == 0)
				if (check_step3(com, &a, &b) == -1)
				{
					finish_check(&a, &b);
					return (0);
				}
		if (flag == 1)
			ft_print(a, b);
		free(com);
	}
	if (!stacks_is_sort(a, b))
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	finish_check(&a, &b);
	return (0);
}