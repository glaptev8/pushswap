#include "../includes/push_swap.h"

int		stacks_is_sort(t_num *a, t_num *b)
{
	int		ferst_a;
	int		ferst_b;
	int 	flag;

	flag = b->index == -1 ? 1 : 0;
	if (flag == 0)
		return (0);
	ferst_a = a->num;
	ferst_b = b->num;
	if (a->num < a->next->num)
		a = a->next;
	else
		return (0);
	if (b->next && b->num > b->next->num)
		b = b->next;
	else
		return (0);
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
	int d;
	while (a->next != NULL && !stacks_is_sort(a, b))
	{
//
		if (a->num > a->next->num)
			a = ft_sa(a);
		if (a->num > a->prev->num)
			a = ft_rra(a);
		if (!(a->num > a->prev->num || a->num > a->next->num))
		{
			b = ft_pb(&a, b);
			if (b->next)
			{
				while (b->num < b->prev->num)
					b = ft_rrb(b);
				if (b->num < b->next->num)
				{
					while (b->num < b->next->num)
						a = ft_pa(a, &b);
				}
			}
		}
	}

	// нужно вывод
	if (b)
	{
		while (b)
		{
			a = lst_add(a, b->num);
			if (b->next)
				b = lst_remove(b);
			else
				break;
		}
	}
	d = a->num;

	printf("%d  ", a->num);
	a = a->next ? a->next : a;
	while (a->next && a->num != d)
	{
		printf("%d  ", a->num);
		a = a->next;
	}
	printf ("\n");
}

int main(int argc, char **argv)
{
	int n[6] = {1, 2, 4, 5, 3, 10};
	int i = 0;

	t_num *a;
	t_num *b;

	a = lst_new(6);
	while (i < 6)
	{
		a->num = n[i];
		a = a->next;
		i++;
	}
//	b = lst_new(0);
	push_swap(a, b);
	return 1;
}
