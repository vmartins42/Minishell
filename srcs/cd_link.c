/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_link.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 14:02:18 by vmartins          #+#    #+#             */
/*   Updated: 2017/10/27 13:56:21 by vmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*back_link(char *elem_tab, char *getenv, int i)
{
	struct stat	sb;
	char		*temp;

	if (ft_strncmp(elem_tab, "../", 2) == 0)
	{
		while (getenv[i])
		{
			i = (getenv[i] == '/') ? i + 1 : i + 0;
			while (getenv[i] && getenv[i] != '/')
				i++;
			temp = ft_strsub(getenv, 0, i);
			lstat(temp, &sb);
			if (S_ISLNK(sb.st_mode))
			{
				ft_strdel(&temp);
				temp = ft_removendslash(getenv);
				if (ft_theirisnothing(temp))
					temp = ft_strdup("/private");
				return (temp);
			}
			ft_strdel(&temp);
		}
		return ((temp = ft_getcwd()));
	}
	return (NULL);
}

char	*go_link(char *elem_tab, char **env)
{
	struct stat	sb;
	char		*temp;
	char		*getenv;
	char		*tmp;

	temp = NULL;
	if ((getenv = get_env("PWD", env)))
	{
		if (getenv[0] == '/' && !getenv[1])
			temp = ft_strjoin(getenv, elem_tab);
		else
			temp = ft_triplejoin(getenv, elem_tab);
		if (getenv)
			ft_strdel(&getenv);
	}
	lstat(temp, &sb);
	if ((tmp = check_link(temp, env)))
	{
		ft_strdel(&tmp);
		return (temp);
	}
	else
		return (NULL);
	ft_strdel(&elem_tab);
}

char	*check_link(char *elem_tab, char **env)
{
	struct stat	sb;
	char		*temp;
	int			i;

	i = 0;
	while (elem_tab[i])
	{
		if (elem_tab[i] == '/' && elem_tab[i] != '.')
			i++;
		else
			return ((temp = go_link(elem_tab, env)));
		while (elem_tab[i] && elem_tab[i] != '/')
			i++;
		temp = ft_strsub(elem_tab, 0, i);
		lstat(temp, &sb);
		if (S_ISLNK(sb.st_mode))
		{
			ft_strdel(&temp);
			return ((temp = ft_strdup(elem_tab)));
		}
		ft_strdel(&temp);
	}
	if (temp)
		ft_strdel(&temp);
	return ((temp = ft_getcwd()));
}
