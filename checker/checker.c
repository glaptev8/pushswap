#include "../includes/push_swap.h"
#include "../libft/libft.h"

int			ft_is_number(char *num)
{
	int		i;

	i = 0;
	if (num[i] == '-')
		i++;
	while (num[i])
	{
		if (!(num[i] <= '9' && num[i] >= '0'))
			return (0);
		i++;
	}
	return (1);
}

int		stacks_is_sort(t_num *a, t_num *b)
{
	int		ferst_a;
	int		ferst_b;
	int 	flag;

	if (!a || !a->next)
		return (1);
	ferst_a = a->num;
	while (a->num < a->next->num)
		a = a->next;
	if (a->next->num != ferst_a)
		return (0);
	if (!b)
		return (1);
	if (ferst_a < b->num)
		return (0);
	return (1);
}

int				ft_init_stack(t_num **stacks, int ac, char **av)
{
	int i;

	i = 0;
	if (av[1] && !ft_strcmp(av[1], "-v"))
		i++;
	while (++i < ac)
	{
		if (ft_is_number(av[i]))
			(*stacks)->num = ft_atoi(av[i]);
		else
			return (0);
		*stacks = (*stacks)->next;
	}
	return (1);
}

int main(int argc, char **argv)
{
	t_num *a;
	t_num *b;
	char *com;

	a = lst_new(argc - 1);
	if (argc == 1 || (argc == 2 && !ft_strcmp(argv[1], "-v")))
		return (0);
	if (ft_init_stack(&a, argc, argv) == 0)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	ft_print(a, b);
	while (get_next_line(0, &com) != 0)
	{
		if (!ft_strcmp(com, "sa"))
			a = ft_sa(a);
		else if (!ft_strcmp(com, "sb"))
		{
			if (b)
				b = ft_sb(b);
		}
		else if (!ft_strcmp(com, "ra"))
			a = ft_ra(a);
		else if (!ft_strcmp(com, "rb"))
			b = ft_rb(b);
		else if (!ft_strcmp(com, "rra"))
			a = ft_rra(a);
		else if (!ft_strcmp(com, "rrb"))
			b = ft_rrb(b);
		else if (!ft_strcmp(com, "pb"))
		{
			if (a && a->next && a->next != a)
			{
				b = ft_pb(&a, b);
			}
			else if (a)
			{
				b = lst_add(b, a->num);
				a = NULL;
				free(a);
			}
		}
		else if (!ft_strcmp(com, "pa"))
		{
			if (b && b->next && b->next != b)
				a = ft_pa(a, &b);
			else if (b)
			{
				a = lst_add(a, b->num);
				b = NULL;
				free(b);
			}
		}
		else if (!ft_strcmp(com, "rrr"))
			ft_rrr(&a, &b);
		else if (!ft_strcmp(com, "rr"))
			ft_rr(&a, &b);
		else
		{
			ft_putstr_fd("Error\n", 2);
			free(com);
			return (0);
		}
		if (!ft_strcmp(argv[1], "-v"))
			ft_print(a, b);
		free(com);
	}
	if (!stacks_is_sort(a, b))
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
//	printf("(%d)", get_struct_len(a) + 1);
	clear(&a, get_struct_len(a) + 1);
	if (!b || ((b && !b->next) || (b && b->next && b->next == b) ))
		free(b);
	else
		clear(&b, get_struct_len(b) + 1);
	return (0);
}