/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 13:29:17 by vmartins          #+#    #+#             */
/*   Updated: 2017/09/20 13:54:47 by vmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*get_env(char *elem_tab, char **env)
{
	int		i;
	int		j;
	char	*result;

	i = -1;
	result = NULL;
	while (env[++i])
	{
		j = 0;
		if (ft_isenv(env[i], elem_tab))
		{
			while (env[i][j] != '=')
				j++;
			j++;
			result = ft_strsub(env[i], j, ft_strlen(env[i]) - j);
			return (result);
		}
	}
	return (result);
}

int		ft_echo(char **tab, t_shell *shell)
{
	int		i;
	char	*tmp;

	i = 0;
		while (tab[++i])
		{
			if (tab[i][0] == '$')
				tab[i] = get_env((tab[i] + 1), shell->env);
			tmp = tab[i];
			tab[i] = ft_escapequote(tab[i]);
			ft_strdel(&tmp);
			if (tab[i])
			{
				ft_putstr(tab[i]);
				ft_putchar(' ');
			}
		}
	ft_putstr("\n");
	return (1);
}
