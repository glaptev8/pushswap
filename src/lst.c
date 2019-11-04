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

	lst = lst_create();
	tmp = lst;
	while (--len)
	{
		lst->next = lst_create();
		lst->next->prev = lst;
		lst = lst->next;
	}
	tmp->prev = lst;
	lst->next = tmp;
	return (lst);
}
