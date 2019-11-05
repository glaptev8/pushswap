#include "../includes/push_swap.h"

t_num	*lst_create(void)
{
	t_num *lst;

	lst = (t_num *)malloc(sizeof(t_num));
	lst->index = -1;
	lst->num = 0;
	lst->next = NULL;
	lst->prev = NULL;
	return (lst);
}

t_num	*lst_new(int len)
{
	t_num *lst;
	t_num *tmp;

	if (len == 0)
	{
		lst = lst_create();
		lst->next = lst;
		lst->prev = lst;
		return (lst);
	}
	lst = lst_create();
	tmp = lst;
	while (--len > 0)
	{
		lst->next = lst_create();
		lst->next->prev = lst;
		lst = lst->next;
	}
	tmp->prev = lst;
	lst->next = tmp;
	return (lst);
}

t_num	*lst_add(t_num *a, int n)
{
	t_num *b;

	b = lst_create();
	if (!a || a->index != -1)
		b->num = n;
	else if (a->next == NULL && a->prev == NULL)
	{
		b->num = n;
		a->next = b;
		a->prev = b;
		b->next = a;
		b->next->num = a->num;
		b->prev = a;
	}
	else
	{
		b->num = n;
		b->next = a;
		b->prev = a->prev;
		b->next->prev->next = b;
		b->next->prev = b;
	}
	return (b);
}

t_num *lst_remove(t_num *a)
{
	t_num *b;

	b = a->next;
	b->prev = b->prev->prev;
	b->prev->next = b;
	if (b == b->next && b == b->prev)
	{
		b->prev = NULL;
		b->next = NULL;
	}
	return (b);
}
