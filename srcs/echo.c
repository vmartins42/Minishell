/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 13:29:17 by vmartins          #+#    #+#             */
/*   Updated: 2017/10/30 12:33:58 by vmartins         ###   ########.fr       */
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

void	ft_print_dollar(char *line)
{
	int		i;
	int		j;
	char	*str;

	if ((str = (char *)malloc(sizeof(char) * (ft_strlen(line) + 1))) == NULL)
	{
		ft_putendl_fd("Error Malloc", 2);
		exit(0);
	}
	i = -1;
	j = 0;
	while (line[++i])
	{
		str[j++] = line[i];
		if (line[i] == '$')
			break ;
	}
	str[j] = '\0';
	ft_putstr(str);
	ft_putchar(' ');
	free(str);
}

int		ft_echo(char **tab, t_shell *shell, int i)
{
	char	*tmp;

	tmp = NULL;
	while (tab[++i])
	{
		if (tab[i][0] == '$')
		{
			if ((tmp = get_env((tab[i] + 1), shell->env)) != NULL)
			{
				ft_putstr(tmp);
				ft_putchar(' ');
				free(tmp);
			}
			else
			{
				if (ft_strlen(tab[i]) == 1 && tab[i][0] == '$')
					ft_putstr(tab[i]);
			}
		}
		else
			ft_print_dollar(tab[i]);
	}
	ft_putstr("\n");
	return (1);
}
