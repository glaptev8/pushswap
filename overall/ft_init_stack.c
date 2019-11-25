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

int				valid_atoi(const char **str)
{
	int sign;

	sign = 1;
	while (**str && ((**str >= 9 && **str <= 13) || **str == ' '))
		(*str)++;
	if (**str == '-')
		sign = -1;
	if ((**str == '-' || **str == '+') &&
	**(str - 1) != '-' && **(str - 1) != '+')
		(*str)++;
	while (**str == '0')
		(*str)++;
	return (sign);
}

long int		ft_atoi_push(const char *str, int *flag)
{
	long int	num;
	long int	sign;
	long int	border;

	num = 0;
	sign = 1;
	border = (long int)(FT_LONG_MAX / 10);
	sign = valid_atoi(&str);
	while (*str && *str >= '0' && *str <= '9')
	{
		if ((num > border || (num == border && (*str))) && sign > 0)
		{
			*flag = 1;
			return (-1);
		}
		else if ((num > border || (num == border && (*str))) && sign == -1)
		{
			*flag = 1;
			return (0);
		}
		num = num * 10 + (long int)(*str - '0');
		str++;
	}
	return ((long int)(num * sign));
}

int				ft_init_stack(t_num **stacks, int ac, char **av)
{
	int i;
	int flag;

	flag = 0;
	i = -1;
	while (++i < ac)
	{
		if (!ft_strcmp(av[i], "-"))
			return (0);
		if (ft_is_number(av[i]))
		{
			if (ft_atoi_push(av[i], &flag) > 2147483647 ||
					ft_atoi_push(av[i], &flag) < -2147483648)
				return (0);
			if (flag == 1)
				return (0);
			(*stacks)->num = ft_atoi(av[i]);
		}
		else
			return (0);
		*stacks = (*stacks)->next;
	}
	return (1);
}
