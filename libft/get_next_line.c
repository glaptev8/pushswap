/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmelia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 13:35:01 by tmelia            #+#    #+#             */
/*   Updated: 2019/09/23 13:35:18 by tmelia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		new_str(char **str, int fd, char **line)
{
	size_t		len;
	char		*tmp;

	len = 0;
	while (str[fd][len] != '\0' && str[fd][len] != '\n')
		len++;
	*line = ft_strsub(str[fd], 0, len);
	tmp = ft_strdup(str[fd] + len + (str[fd][len] == '\n' ? 1 : 0));
	free(str[fd]);
	if (tmp != '\0')
		str[fd] = tmp;
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*str[10];
	char		*tmp;
	int			ret;
	char		buf[BUFF_SIZE + 1];

	if (fd < 0 || !line)
		return (-1);
	ret = 0;
	if ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!str[fd])
			str[fd] = ft_strnew(ret - 1);
		tmp = ft_strjoin(str[fd], buf);
		free(str[fd]);
		str[fd] = tmp;
	}
	if (ret < 0)
		return (-1);
	if (ret == 0 && (!str[fd] || (str[fd] && str[fd][0] == '\0')))
		return (0);
	return (new_str(str, fd, line));
}
