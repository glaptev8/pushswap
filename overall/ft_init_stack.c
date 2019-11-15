/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmelia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 17:36:33 by tmelia            #+#    #+#             */
/*   Updated: 2019/11/15 17:36:34 by tmelia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int				ft_init_stack(t_num **stacks, int ac, char **av)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (i < ac)
	{
		if (ft_is_number(av[i]))
		{
			if (ft_atoi(av[i]) > 2147483647 ||
					ft_atoi(av[i]) < -2147483648)
				return (0);
			(*stacks)->num = ft_atoi(av[i]);
		}
		else
			return (0);
		*stacks = (*stacks)->next;
		i++;
	}
	return (1);
}
