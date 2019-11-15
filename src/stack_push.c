/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmelia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 17:17:55 by tmelia            #+#    #+#             */
/*   Updated: 2019/11/15 17:17:57 by tmelia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		stack_push(t_num **a, int argc, char **s)
{
	if (ft_init_stack(a, argc, s) == 0)
	{
		clear(a, argc);
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	if (has_dublicat(s, argc) == -1)
	{
		clear(a, argc);
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	return (1);
}
