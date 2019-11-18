/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmelia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 17:36:51 by tmelia            #+#    #+#             */
/*   Updated: 2019/11/15 17:36:54 by tmelia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		get_struct_len(t_num *a)
{
	t_num	*q;
	int		i;

	i = 0;
	q = a;
	if (a == a->next)
		return (0);
	if (a && a->next && a != a->next)
		q = a->next;
	while (q && q->next && q != a)
	{
		i++;
		q = q->next;
	}
	return (i);
}

int		get_pos(t_num *a, int n)
{
	int i;

	i = 0;
	while (a->num != n)
	{
		i++;
		if (a != a->next)
			a = a->next;
		else
			return (0);
	}
	return (i);
}

int		get_second_min(t_num *a, int min)
{
	int		m;
	t_num	*q;

	m = a->num;
	q = a->next;
	while (q != a)
	{
		if (q->num < m && q->num != min)
			m = q->num;
		q = q->next;
	}
	q = NULL;
	return (m);
}

int		get_max(t_num *a)
{
	t_num	*q;
	int		max;

	if (a && !a->next)
		return (a->num);
	if (a == a->next)
		return (a->num);
	max = a->num;
	q = a->next;
	while (q != a)
	{
		if (q->num > max)
			max = q->num;
		q = q->next;
	}
	return (max);
}

int		get_min(t_num *a)
{
	t_num	*q;
	int		min;

	if (a && !a->next)
		return (a->num);
	if (a == a->next)
		return (a->num);
	min = a->num;
	q = a->next;
	while (q != a)
	{
		if (q->num < min)
			min = q->num;
		q = q->next;
	}
	return (min);
}
