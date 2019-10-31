#include <string.h>

typedef struct		s_num
{
	int num;
	int index;
	struct s_num	*next;
	struct s_num	*prev;

}					t_num;

t_num	*lst_create(void)
{
	t_num *lst;

	lst = (t_num *)malloc(sizeof(t_num));
	lst->index = 0;
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

void	push_swap()
{
	int n[6] = {2, 1, 3, 6, 5, 8};

	t_num *a;
	t_num *b;
	t_num *a_f;
	t_num *b_f;
	a = (t_num *)malloc(sizeof(t_num) * 6);
	b = (t_num *)malloc(sizeof(t_num) * 6);
	a_f = (t_num *)malloc(sizeof(t_num) * 6);
	b_f = (t_num *)malloc(sizeof(t_num) * 6);
	a = lst_new(6);
	a_f = a;
	int i = 0;
	while (i < 6)
	{
		a->num = n[i];
		a = a->next;
		i++;
	}
	while (i-- > 0)
	{
		printf("%d", a_f->num);
		a_f = a_f->next;
	}
}

void main()
{
	push_swap();
}
