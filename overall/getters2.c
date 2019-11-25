/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmelia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 13:46:50 by tmelia            #+#    #+#             */
/*   Updated: 2019/11/25 13:46:53 by tmelia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		get_next(t_num *a, int n)
{
	int		i;
	t_num	*q;

	q = a;
	i = 0;
	if (a->num <= n)
		return (1);
	a = a->next;
	while (a->num > n && a != q)
	{
		i++;
		a = a->next;
	}
	return (i);
}

int		get_prev(t_num *a, int n)
{
	int		i;
	t_num	*q;

	i = 0;
	q = a;
	i = 0;
	if (a->num <= n)
		return (1);
	a = a->prev;
	while (a->num > n && a != q)
	{
		i++;
		a = a->prev;
	}
	return (get_struct_len(a) - i);
}

int		get_next2(t_num *a, int n)
{
	int		i;
	t_num	*q;

	q = a;
	i = 0;
	if (a->num >= n)
		return (1);
	a = a->next;
	while (a->num < n && a != q)
	{
		i++;
		a = a->next;
	}
	return (i);
}

int		get_prev2(t_num *a, int n)
{
	int		i;
	t_num	*q;

	i = 0;
	q = a;
	i = 0;
	if (a->num >= n)
		return (1);
	a = a->prev;
	while (a->num < n && a != q)
	{
		i++;
		a = a->prev;
	}
	return (get_struct_len(a) - i);
}

int		get_second_max(t_num *a, int max)
{
	int		m;
	t_num	*q;

	m = a->num;
	q = a->next;
	while (q != a)
	{
		if (q->num > m && q->num != max)
			m = q->num;
		q = q->next;
	}
	q = NULL;
	return (m);
}
