#include "../includes/push_swap.h"
#include "../libft/libft.h"

int main(int argc, char **argv)
{
	t_num *a;
	t_num *b;
	char *com;
	int flag = 0;

	if (argc == 1 || (argc == 2 && !ft_strcmp(argv[1], "-v")))
		return (0);
	if (!ft_strcmp(argv[1], "-v"))
	{
		flag = 1;
		argc--;
		argv++;
	}
	a = lst_new(argc - 1);
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
				free(a);
				a = NULL;
			}
		}
		else if (!ft_strcmp(com, "pa"))
		{
			if (b && b->next && b->next != b)
				a = ft_pa(a, &b);
			else if (b)
			{
				a = lst_add(a, b->num);
				free(b);
				b = NULL;
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
		if (flag == 1)
			ft_print(a, b);
		free(com);
	}
	if (!stacks_is_sort(a, b))
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	if (!a || ((a && !a->next) || (a && a->next && a->next == a) ))
	{
		free(a);
	}
	else
		clear(&a, get_struct_len(a) + 1);
	if (!b || ((b && !b->next) || (b && b->next && b->next == b) ))
		free(b);
	else
	{
		clear(&b, get_struct_len(b) + 1);
	}
	return (0);
}