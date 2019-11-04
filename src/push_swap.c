#include "../includes/push_swap.h"

int		stacks_is_sort(t_num *a, t_num *b)
{

}

void	push_swap(t_num *a, t_num *b)
{
	int d;

	if (a->num > a->next->num)
		a = ft_sa(a);
	if (a->num > a->prev->num)
		a = ft_rra(a);
	if (!(a->num > a->prev->num || a->num > a->next->num))
		b = ft_pb(&a, b);
	d = b->num;

	printf("%d  ", b->num);
	b = b->next ? b->next : b;
	while (b->next && b->num != d)
	{
		printf("%d  ", b->num);
		b = b->next;
	}
	printf ("\n");
if (a->next != NULL)
	push_swap(a, b);
//	while (!stacks_is_sort(a, b))
//	{
//
//	}
}

int main(int argc, char **argv)
{
	int n[5] = {45,44,38, 22, 77};
	int i = 0;

	t_num *a;
	t_num *b;

	a = lst_new(5);
	while (i < 5)
	{
		a->num = n[i];
		a = a->next;
		i++;
	}
//	b = lst_new(0);
	push_swap(a, b);
	return 1;
}
