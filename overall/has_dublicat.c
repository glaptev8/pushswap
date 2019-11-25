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

	i = -1;
	while (++i < argc)
	{
		j = -1;
		while (++j < i)
		{
			if ((!ft_strcmp(s[i], "-0") || !ft_strcmp(s[i], "0")) &&
			(!ft_strcmp(s[j], "-0") || (!ft_strcmp(s[j], "0"))))
			{
				ft_putstr_fd("Error\n", 2);
				return (-1);
			}
			if (!ft_strcmp(s[i], s[j]))
			{
				ft_putstr_fd("Error\n", 2);
				return (-1);
			}
		}
	}
	return (1);
}
