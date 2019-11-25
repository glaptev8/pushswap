/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   average3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmelia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 13:23:12 by tmelia            #+#    #+#             */
/*   Updated: 2019/11/25 13:23:13 by tmelia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_init_average(t_num *a, int min, int *average, int flag)
{
	int len;

	len = get_struct_len(a) + 1;
	if (flag == 1)
	{
		average[0] = ft_average(a, len, min);
		average[1] = ft_average2(a, len, average[0]);
		average[2] = ft_average2(a, len, average[1]);
		average[3] = ft_average2(a, len, average[2]);
		average[4] = ft_average2(a, len, average[3]);
		average[5] = ft_average2(a, len, average[4]);
		average[6] = ft_average2(a, len, average[5]);
		average[7] = ft_average2(a, len, average[6]);
	}
	else
	{
		average[0] = ft_average(a, len, min);
		average[1] = ft_average(a, len, average[0]);
		average[2] = ft_average(a, len, average[1]);
		average[3] = ft_average(a, len, average[2]);
		average[4] = ft_average(a, len, average[3]);
		average[5] = ft_average(a, len, average[4]);
		average[6] = ft_average(a, len, average[5]);
		average[7] = ft_average(a, len, average[6]);
	}
}

int		biger_min(t_num *a, int min)
{
	t_num	*q;
	int		count;

	count = 0;
	if (a->num > min)
		count++;
	q = a;
	a = a->next;
	while (a != q)
	{
		if (a->num > min)
			count++;
		a = a->next;
	}
	return (count);
}
