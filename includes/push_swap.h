#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <string.h>
#include <stdlib.h>

int count;

typedef struct		s_num
{
	int num;
	int index;
	struct s_num	*next;
	struct s_num	*prev;

}					t_num;

t_num	*lst_new(int len);
t_num	*lst_create(void);
t_num		*ft_sa(t_num *a);
t_num		*ft_rra(t_num *a);
t_num		*ft_pa(t_num *a, t_num **b);
int		stacks_is_sort(t_num *a, t_num *b);
t_num		*ft_pb(t_num **a, t_num *b);
t_num	*lst_add(t_num *a, int n);
t_num *lst_remove(t_num *a);
t_num		*ft_sb(t_num *b);
t_num		*ft_rrb(t_num *b);
#endif