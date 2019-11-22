/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmelia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 16:10:01 by tmelia            #+#    #+#             */
/*   Updated: 2019/11/15 16:10:07 by tmelia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "libft.h"

static int		ft_count_words(char const *s, char c)
{
	int			nb_words;
	int			str_test;

	nb_words = 0;
	str_test = 0;
	while (*s != '\0')
	{
		if (str_test == 1 && *s == c)
			str_test = 0;
		if (str_test == 0 && *s != c)
		{
			str_test = 1;
			nb_words++;
		}
		s++;
	}
	return (nb_words);
}

static int		ft_word_length(char const *s, char c)
{
	size_t		i;

	i = 0;
	while (*s && *s != c)
	{
		i++;
		s++;
	}
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**my_tab;
	int			i;
	int			nb_words;

	i = 0;
	if (!s)
		return (NULL);
	nb_words = ft_count_words(s, c);
	my_tab = (char **)malloc(sizeof(char *) * nb_words + 1);
	if (my_tab == NULL)
		return (NULL);
	while (nb_words--)
	{
		while (*s == c && *s != '\0')
			s++;
		if ((my_tab[i++] = ft_strsub(s, 0, ft_word_length(s, c))) == NULL)
		{
			free(my_tab);
			return (NULL);
		}
		s += ft_word_length(s, c);
	}
	my_tab[i] = NULL;
	return (my_tab);
}
