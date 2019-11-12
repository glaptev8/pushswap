#include "../includes/push_swap.h"

int		sort_one(t_num **a, t_num *b)
{
	if (stacks_is_sort((*a)->next, b))
	{
		(*a) = ft_ra((*a));
		ft_print((*a), b);
		return (0);
	}
	if (stacks_is_sort((*a)->prev, b))
	{
		(*a) = ft_rra((*a));
		ft_print((*a), b);
		return (0);
	}
	return (1);
}

t_num	*step(int to, int min, t_num *a)
{
	if (to == 1 && a->num != min)
		a = ft_ra(a);
	else if (a->num != min)
		a = ft_rra(a);
	return (a);
}

t_num	*ft_sort(t_num *a, t_num **b)
{
	int to;
	int max;
	int z;
	int min;

	int i = 9;
	min = get_min(a);
	z = get_second_min(a, min);
	max = get_max(a);
	to = ft_direction(get_pos(a, z), get_pos(a, min), get_pos(a, max), get_struct_len(a));
	while (a->num != min && !stacks_is_sort(a, (*b)) && --i > 0)
	{
		if (a->num == z && !stacks_is_sort(a, (*b)))
		{
			(*b) = ft_pb(&a, (*b));
			ft_print(a, (*b));
			break;
		}
		if ((*b) && (*b)->next && a->num == max && !stacks_is_sort(a, (*b)))
		{
			(*b) = ft_pb(&a, (*b));
			ft_print(a, (*b));
			(*b) = ft_rb((*b));
			ft_print(a, (*b));
			break;
		}
		a = step(to, min, a);
	}
	return (a);
}

t_num *ft_oper(t_num *a, t_num **b)
{
	int min;

	min = get_min(a);
	a = ft_sort(a, b);
	if (a->num == min && !stacks_is_sort(a, (*b)))
	{
		(*b) = ft_pb(&a, (*b));
		ft_print(a,(*b));
		if ((*b)->next && (*b)->num < (*b)->next->num)
		{
			(*b) = ft_sb((*b));
			ft_print(a,(*b));
		}
	}
	return (a);
}