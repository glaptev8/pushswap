#include "../includes/push_swap.h"

int				ft_init_stack(t_num **stacks, int ac, char **av)
{
	int i;

	i = 0;
	while (++i < ac)
	{
		if (ft_is_number(av[i]))
		{
//			printf("%lu ",ft_atoi(av[i]));
			if (ft_atoi(av[i]) > 2147483647 ||
					ft_atoi(av[i]) < -2147483648)
				return (0);
			(*stacks)->num = ft_atoi(av[i]);
		}
		else
			return (0);
		*stacks = (*stacks)->next;
	}
	return (1);
}