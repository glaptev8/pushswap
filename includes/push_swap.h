#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <string.h>
#include <stdlib.h>

typedef struct		s_num
{
	int num;
	int index;
	struct s_num	*next;
	struct s_num	*prev;

}					t_num;

t_num	*lst_new(int len);
t_num	*lst_create(void);
void		ft_sa(t_num *a);
void		ft_rra(t_num **a);
void		ft_pa(t_num **a, t_num **b);
void		ft_rrb(t_num **b);
int		stacks_is_sort(t_num *a, t_num *b);
#endif