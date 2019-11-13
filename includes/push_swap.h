#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "../libft/libft.h"
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
void    ft_display_a(t_num *a);
t_num		*ft_sa(t_num *a);
t_num		*ft_rra(t_num *a);
t_num		*ft_pa(t_num *a, t_num **b);
int		stacks_is_sort(t_num *a, t_num *b);
t_num	*lst_add(t_num *a, int n);
t_num *lst_remove(t_num **a);
t_num		*ft_sb(t_num *b);
t_num		*ft_rrb(t_num *b);
t_num		*ft_ra(t_num *a);
t_num		*ft_rb(t_num *b);
t_num		*ft_pa(t_num *a, t_num **b);
t_num		*ft_pb(t_num **a, t_num *b);
void	ft_rr(t_num **a, t_num **b);
void	ft_rrr(t_num **a, t_num **b);
int		get_second_min(t_num *a, int min);
int		get_max(t_num *a);
int		get_min(t_num *a);
int		get_struct_len(t_num *a);
int			ft_is_number(char *num);
int				ft_init_stack(t_num **stacks, int ac, char **av);
int		get_pos(t_num *a, int n);
int		ft_direction(int x, int d, int m, int y);
void	ft_oper(t_num **a, t_num **b);
int		sort_one(t_num **a, t_num *b);
void	step(int to, int min, t_num **a);
void	ft_print(t_num *a, t_num *b);
int			ft_printf(const char *format, ...);
#endif