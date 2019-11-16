/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_dublicat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmelia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 17:37:00 by tmelia            #+#    #+#             */
/*   Updated: 2019/11/15 17:37:02 by tmelia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		has_dublicat(char **s, int argc)
{
	int i;
	int j;

	i = 0;
	while (i < argc)
	{
		j = 0;
		while (j < i)
		{
			if (!ft_strcmp(s[i], s[j]))
			{
				ft_putstr_fd("Error\n", 2);
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (1);
}
