/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmelia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 19:27:02 by tmelia            #+#    #+#             */
/*   Updated: 2019/11/15 19:27:08 by tmelia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct		s_num
{
	int				num;
	int				index;
	struct s_num	*next;
	struct s_num	*prev;

}					t_num;

t_num				*lst_new(int len);
t_num				*lst_create(void);
void				ft_display_a(t_num *a);
t_num				*ft_sa(t_num *a);
t_num				*ft_rra(t_num *a);
t_num				*ft_pa(t_num *a, t_num **b);
int					stacks_is_sort(t_num *a, t_num *b);
t_num				*lst_add(t_num *a, int n);
t_num				*lst_remove(t_num **a);
t_num				*ft_sb(t_num *b);
t_num				*ft_rrb(t_num *b);
t_num				*ft_ra(t_num *a);
t_num				*ft_rb(t_num *b);
t_num				*ft_pa(t_num *a, t_num **b);
t_num				*ft_pb(t_num **a, t_num *b);
void				ft_rr(t_num **a, t_num **b);
void				ft_rrr(t_num **a, t_num **b);
int					get_second_min(t_num *a, int min);
int					get_max(t_num *a);
int					get_min(t_num *a);
int					get_struct_len(t_num *a);
int					ft_is_number(char *num);
int					ft_init_stack(t_num **stacks, int ac, char **av);
int					get_pos(t_num *a, int n);
int					ft_direction(int x, int d, int m, int y);
void				ft_oper(t_num **a, t_num **b);
int					sort_one(t_num **a, t_num *b);
void				ft_print(t_num *a, t_num *b);
int					ft_printf(const char *format, ...);
void				clear(t_num **t, int n);
void				finish_check(t_num **a, t_num **b, char **s);
int					check_step3(char *com, t_num **a, t_num **b);
int					valid_check(char **s, int *argc, int *flag, t_num **a);
char				**check_str(int *argc, char ***argv);
int					ft_check_step(t_num **a, t_num **b, int flag);
int					has_dublicat(char **s, int argc);
int					check_step(char *com, t_num **a, t_num **b);
int					init_check(int *argc, char **argv, t_num **a, int *flag);
int					check_step2(char *com, t_num **a, t_num **b);
int					stack_push(t_num **a, int argc, char **s);
void				fresh(char **s);
int					is_a_sort(t_num *a);
int					average(t_num *a, int len);
int					more_average(t_num *a, int n, int min);
void				ft_init_average(t_num *a, int min, int *average, int flag);
void				ft_pushb_a(t_num **a, t_num **b);
void				sort_three(t_num **a);
int					get_next(t_num *a, int n);
int					get_prev(t_num *a, int n);
int					get_next2(t_num *a, int n);
int					get_prev2(t_num *a, int n);
int					get_second_max(t_num *a, int max);
void				while_more_average2(t_num **a, t_num **b,
		int average, int average2);
int					ft_average(t_num *a, int len, int min);
int					ft_average2(t_num *a, int len, int min);
int					more_average(t_num *a, int n, int min);
void				sort_five(t_num **a, t_num **b);
void				sort_three(t_num **a);
void				ft_sort(t_num **a, t_num **b);
void				while_more_average(t_num **a, t_num **b,
		int average, int average2);
void				push_last_a(t_num **a, t_num **b, int *average);
void				step_for_b(t_num **a, t_num **b, int *average);
int					more_average2(t_num *a, int n, int min);
void				step_for_a(t_num **a, t_num **b, int *average);
#endif
