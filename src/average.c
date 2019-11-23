#include "../includes/push_swap.h"

void	while_more_average(t_num **a, t_num **b, int average, int average2)
{
	int min;
	int max;
	int next;
	int prev;
	int to;

	max = get_max(*a);
	if (*b)
		min = get_min(*b);
	else
		min = get_min(*a) - 1;
	while (more_average(*a, average2, min))
	{

		next = get_next(*a, average2);
		prev = get_prev(*a, average2);
		to = ft_direction(1, next, prev, get_struct_len(*a));
		if ((*a)->num <= average && (*a)->num > min && (*a)->num != max)
		{
			*b = ft_pb(a, *b);
			if ((*b)->next && (*b) != (*b)->next && (*b)->num <= average2)
				*b = ft_rb(*b);
			next = get_next(*a, average2);
			prev = get_prev(*a, average2);
			to = ft_direction(1, next, prev, get_struct_len(*a));
		}
		else if (to == 2)
			*a = ft_rra(*a);
		else
			*a = ft_ra(*a);
	}
}

void	while_more_average2(t_num **a, t_num **b, int average, int average2)
{
	int min;
	int max;
	int next;
	int prev;
	int to;

	max = get_max(*b);
	min = (*b) ? get_min(*b) : get_min(*a) - 1;
	while (more_average2(*b, average2, min))
	{
		next = get_next2(*b, average2);
		prev = get_prev2(*b, average2);
		to = ft_direction(1, next, prev, get_struct_len(*b));
		if ((*b)->num >= average)
		{
			*a = ft_pa(*a, b);
			to = ft_direction(1, next, prev, get_struct_len(*a));
			if ((*a)->next && (*a) != (*a)->next && (*a)->num <= average2)
					*a = ft_ra(*a);
		}
		else if (to == 2)
			*b = ft_rrb(*b);
		else
			*b = ft_rb(*b);
	}
}

void	ft_init_average(t_num *a, int min, int *average, int flag)
{
	int len;

	len = get_struct_len(a) + 1;
	if (flag == 1)
	{
		average[0] = ft_average(a, len, min);
		average[1] = ft_average2(a, len, average[0]);
		average[2] = ft_average2(a, len, average[1]);
		average[3] = ft_average2(a, len, average[2]);
		average[4] = ft_average2(a, len, average[3]);
		average[5] = ft_average2(a, len, average[4]);
		average[6] = ft_average2(a, len, average[5]);
		average[7] = ft_average2(a, len, average[6]);
	}
	else
	{
		average[0] = ft_average(a, len, min);
		average[1] = ft_average(a, len, average[0]);
		average[2] = ft_average(a, len, average[1]);
		average[3] = ft_average(a, len, average[2]);
		average[4] = ft_average(a, len, average[3]);
		average[5] = ft_average(a, len, average[4]);
		average[6] = ft_average(a, len, average[5]);
		average[7] = ft_average(a, len, average[6]);
	}
}

void	step_for_b(t_num **a, t_num **b, int *average)
{
	int min;

	if (*a && (*a)->next && (*a) == (*a)->next)
		*b = ft_pb(a, *b);
	min = get_min(*b);
	while ((*b) && (*b)->next && *b != (*b)->next)
	{
		ft_init_average(*b, min, average, 2);
		if (get_struct_len(*b) > 200)
		{
			if (more_average2(*b, average[4], min) == 0)
				while_more_average2 (a, b, average[2], average[3]);
			while_more_average2 (a, b, average[3], average[4]);
		}
		if (more_average2(*b, average[1], min) == 0)
		{
			while (more_average(*b, average[0], min))
				if ((*b)->num <= average[0])
					*a = ft_pa(*a, b);
				else
					*b = ft_rb(*b);
		}
		if ((*b) && get_struct_len(*b) <= 200)
			while_more_average2 (a, b, average[0], average[1]);
	}
}

void	push_last_a(t_num **a, t_num **b, int *average)
{
	int min;
	int max;

	min = get_min(*a) - 1;
	max = get_max(*a);
	while (*a && (*a)->next && *a != (*a)->next)
	{
		ft_init_average(*a, min, average, 1);
		if (more_average(*a, average[1], min) == 0)
		{
			while (more_average(*a, average[0], min))
			{
				if ((*a)->num <= average[0] && (*a)->num > min && (*a)->num != max)
					*b = ft_pb(a, *b);
				else
					*a = ft_ra(*a);
			}
		}
		while_more_average(a, b, average[0], average[1]);
	}
}

void	step_for_a(t_num **a, t_num **b, int *average)
{
	int min;

	min = (*b && (*b)->next) ? get_min(*b) : get_min(*a) - 1;
	ft_init_average(*a, min, average, 1);
	if (get_struct_len(*a) > 50)
	{
		if (more_average(*a, average[5], min) == 0)
			while_more_average (a, b, average[3], average[4]);
		if (more_average(*a, average[4], min) == 0)
			while_more_average (a, b, average[2], average[3]);
		if (more_average(*a, average[3], min) == 0)
			while_more_average (a, b, average[1], average[2]);
		if (more_average(*a, average[2], min) == 0)
			while_more_average (a, b, average[0], average[1]);
		while_more_average (a, b, average[4], average[5]);
	}
	if (more_average(*a, average[1], min) == 0)
		push_last_a(a, b, average);
	if (get_struct_len(*a) <= 50)
	{
		if (more_average(*a, average[2], min) == 0)
			while_more_average (a, b, average[0], average[1]);
		while_more_average (a, b, average[1], average[2]);
	}
}