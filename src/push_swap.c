#include "../includes/push_swap.h"

int		stacks_is_sort(t_num *a, t_num *b)
{
	int ferst_a;
	int ferst_b;

	ferst_a = a->num;
	if (a->num < a->next->num)
		a = a->next;
	else
		return (0);
	if (b->index == -1 && b->num > b->next->num)
		b = b->next;
	else
		return (0);
	ferst_b = b->num;
	while (a->num < a->next->num)
		a = a->next;
	if (a->num > a->next->num && a->next->num != ferst_a)
		return (0);
	while (b->num > b->next->num && b->num != ferst_b)
		b = b->next;
	if (b->num > ferst_b && b->next->num != ferst_b)
		return (0);
	if (ferst_a < ferst_b)
		return (0);
	return (1);
}

void	push_swap(t_num *a, t_num *b)
{
	static int i = 0;
	t_num *a_f;
	static t_num *b_f;

	a_f = a;
	b_f = b;
	while (!stacks_is_sort(a, b))
	{
		if (a->num != 0 && a->num > a->next->num)
			ft_sa(a);
		else if (a->num != 0 && a->num > a->prev->num)
			ft_rra(&a);
		else
		{
			if (b->index != -1)
			{
				b = lst_create();
				b->prev = b;
				b->next = b;
				b_f = b;
			}
			else
			{
				b->next = lst_create();
				b->next->prev = b;
				b->next->num = b->num;
				b->next->next = b;
				b = b->next;
			}
			if (a->num != 0)
				ft_pb(&a, &b);
			if (b->prev && b->num < b->prev->num)
				ft_rrb(&b);
			if (b->num < b->next->num)
				while (b->num < b->next->num)
					ft_pa(&a, &b);
		}
	}
	while ()
}

int main(int argc, char **argv)
{
	int n[6] = {6, 9, 4, 10};
	int i = 0;

	t_num *a;
	t_num *b;

	a = lst_new(4);
	while (i < 4)
	{
		a->num = n[i];
		a->index = i;
		a = a->next;
		i++;
	}
	push_swap(a, b);
	return 1;
}
