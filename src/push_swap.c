#include "../includes/push_swap.h"
#include <stdlib.h>

int		ft_direction(int x, int d, int m, int y)
{
	int to;

	if (x > d && x > m)
		m < d ? d = m : 0;
	else if (d > x && d > m)
		m < x ? x = m : 0;
	else if (m > d && m > x)
	{
		if (d < x)
			x = m;
		else
			d = m;
	}
	if (x > d)
		to = y - x < d ? 2 : 1;
	else if (y - d <= x - 1 || d == y)
		to = 2;
	else
		to = 1;
	return (to);
}

void	*ft_pushb_a(t_num *b, t_num **a)
{
	while (b != NULL)
	{
		(*a) = ft_pa((*a), &b);
		ft_print((*a), b);
		if (b && b->prev && b->num > b->prev->num)
		{
			b = ft_rrb(b);
			ft_print((*a), b);
		}
		if ((*a)->num > (*a)->prev->num)
		{
			(*a)= ft_ra((*a));
			ft_print((*a), b);
		}
		if ((*a)->num > (*a)->next->num)
		{
			(*a)= ft_sa((*a));
			ft_print((*a), b);
		}
	}
	return ((*a));
}

void	ft_display_a(t_num *a)
{
	int d;

	d = a->num;

	ft_printf("%d ", a->num);
	a = a->next ? a->next : a;
	while (a->next && a->num != d)
	{
		ft_printf("%d ", a->num);
		a = a->next;
	}
	ft_printf ("\n");
}

t_num	*push_swap(t_num *a)
{

}

int main(int argc, char **argv)
{
	count = 0;
	int n[500];
	int i = 0;
	int j;
	t_num *a;

	while (i < 500)
	{
		srand(time(NULL));
		j = 0;
		n[i] = -100 + rand() % 1200;
		while (j < i)
		{
			if (n[j] == n[i])
			{
				n[i] = -100 + rand() % 1200;
				j = -1;
			}
			j++;
		}
		i++;
	}
	int i;
	i = 0;
	a = lst_new(5);
	while (i++ < 5)
	{
		a->num = n[i];
		a = a->next;
	}
	push_swap(a);
}
