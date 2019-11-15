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
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

