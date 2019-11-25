/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmelia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 19:10:45 by tmelia            #+#    #+#             */
/*   Updated: 2019/11/15 19:10:46 by tmelia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char		**check_str(int *argc, char ***argv)
{
	int		i;
	char	**s;

	i = 0;
	if ((*argc == 2) || (*argc == 3 && !ft_strcmp((*argv)[0], "-v")))
	{
		if (*argc == 3)
			s = ft_strsplit((*argv)[1], ' ');
		else
			s = ft_strsplit((*argv)[0], ' ');
		while (s[i])
			i++;
		*argc = i;
		return (s);
	}
	else
		(*argc)--;
	return (NULL);
}
