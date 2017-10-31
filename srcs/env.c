/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 13:12:40 by vmartins          #+#    #+#             */
/*   Updated: 2017/10/27 13:21:21 by vmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	aff_env(char **env)
{
	int		i;

	i = -1;
	while (env[++i])
		ft_putendl(env[i]);
}

int		check_env(char **tab)
{
	int		i;

	i = -1;
	while (tab[++i])
	{
		if (tab[i][0] == '=')
			return (ft_error_setenv(tab[i], "minishell: '", "' not found"));
		else if (!ft_strcmp(tab[i], "cd"))
			return (1);
		else if (!ft_strcmp(tab[i], "unsetenv"))
			return (ft_error_setenv(tab[i], "env : ", \
				": No such file or directory"));
		else if (!ft_strcmp(tab[i], "setenv"))
			return (ft_error_setenv(tab[i], "env : ", \
				": No such file or directory"));
	}
	return (0);
}

int		add_or_modif_env(t_shell *shell, char *elem_tab, int i)
{
	char	*getenv;
	char	*value;
	char	*name;
	int		len;

	len = ft_strlen(elem_tab);
	while (elem_tab[i] != '=')
		i++;
	name = ft_strsub(elem_tab, 0, i);
	value = ft_strsub(elem_tab, i + 1, len);
	if ((getenv = get_env(name, shell->env)))
		modify_env(name, value, &shell);
	else
		shell->env = ft_tabpushback(shell->env, elem_tab);
	ft_strdel(&name);
	ft_strdel(&value);
	ft_strdel(&getenv);
	return (1);
}

int		ft_env(char **tab, t_shell *shell)
{
	if (check_env(tab))
		return (1);
	if (ft_tablen(tab) == 1)
		aff_env(shell->env);
	else if (ft_tablen(tab) == 2)
	{
		if (ft_strchr(tab[1], '='))
		{
			add_or_modif_env(shell, tab[1], 0);
			aff_env(shell->env);
			ft_freetab((void**)shell->env, ft_tablen(shell->env));
			shell->env = ft_tabdup(shell->old_env);
		}
		else
			return (process(&tab[1], shell));
	}
	else
	{
		if (ft_strchr(tab[1], '='))
			return (process(&tab[2], shell));
		else
			return (process(&tab[1], shell));
	}
	return (1);
}
