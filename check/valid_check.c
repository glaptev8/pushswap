/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmelia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 19:11:44 by tmelia            #+#    #+#             */
/*   Updated: 2019/11/15 19:11:47 by tmelia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		valid_check(char **s, int *argc, int *flag, t_num **a)
{
	*flag = *flag;
	*a = *a;
	if (has_dublicat(s, *argc) == -1)
		return (0);
	if (init_check(argc, s, a, flag) == 0)
		return (0);
	return (1);
}
