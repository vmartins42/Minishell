/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 11:09:46 by vmartins          #+#    #+#             */
/*   Updated: 2017/08/21 12:08:13 by vmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_read_n_join(int fd, int *ret, char *buffer)
{
	char	temp[BUFF_SIZE + 1];
	char	*free_get;

	*ret = read(fd, temp, BUFF_SIZE);
	temp[*ret] = '\0';
	free_get = buffer;
	buffer = ft_strjoin(buffer, temp);
	ft_strdel(&free_get);
	return (buffer);
}

int		ft_check(char **buffer, char **line)
{
	char	*rest;

	if ((*buffer) && (ft_strcmp(*buffer, ""))
			&& (rest = ft_strchr(*buffer, '\n')))
	{
		*rest = '\0';
		*line = ft_strdup(*buffer);
		ft_memmove(*buffer, (rest + 1), ft_strlen(rest + 1) + 1);
		return (1);
	}
	else if ((*buffer) && (ft_strcmp(*buffer, "")) && !ft_strchr(*buffer, '\n'))
	{
		*line = ft_strdup(*buffer);
		ft_strdel(buffer);
		return (1);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static char		*buffer;
	int				ret;

	if (read(fd, buffer, 0) < 0)
		return (-1);
	if (!buffer)
		buffer = ft_strnew(0);
	ret = 1;
	while (!ft_strchr(buffer, '\n') && ret > 0)
		buffer = ft_read_n_join(fd, &ret, buffer);
	if (buffer && ft_check(&buffer, line))
		return (1);
	ft_strdel(&buffer);
	return (0);
}
