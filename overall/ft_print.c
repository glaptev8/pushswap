#include "../includes/push_swap.h"

void	ft_print(t_num *a, t_num *b)
{
	int o;
	int d;

	o = a->num;
//	write(1, "\e[1;1H\e[2J", 11);
	ft_printf("%-8s stack2\n", "stack1");
	ft_printf("%-9d", o);
	if (a->next)
		a = a->next;
	if (b)
	{
		d = b->num;
		ft_printf("%d", d);
		if (b->next)
			b = b->next;
	}
	ft_printf("\n");
	while (a->num != o || (b && b->next && b->num != d))
	{
		if (a->num != o && a->next)
		{
			ft_printf("%-9d", a->num);
			a = a->next;
		}
		else ft_printf("         ");
		if (b && b->index == -1 && b->next && b->num != d)
		{
			ft_printf("%d", b->num);
		}
		if (b && b->next && b->num != d)
			b = b->next;
		ft_printf("\n");
	}
	ft_printf("---------------------------------\n");
}
