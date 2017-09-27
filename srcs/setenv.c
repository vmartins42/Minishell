/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 14:42:59 by vmartins          #+#    #+#             */
/*   Updated: 2017/09/20 12:17:13 by vmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		modify_env(char *name, char *value, t_shell **beginshell)
{
	t_shell	*shell;
	char	*temp;
	char	*tmp;
	char	*result;
	int		i;

	i = -1;
	shell = *beginshell;
	while (shell->env[++i])
	{
		if (ft_isenv(shell->env[i], name))
		{
			temp = ft_strjoin(name, "=");
			result = temp;
			ft_strdel(&result);
			temp = ft_strjoin(temp, value);
			tmp = temp;
			ft_strcpy(shell->env[i], temp);
			ft_strdel(&tmp);
		}
	}
	return (1);
}

int		ft_setenv(char **tab, t_shell *shell, char *result, char *temp)
{
	char	*getenv;

	if (!tab[1] || !tab[2])
		return (ft_error_setenv("", "minishell: setenv: ", " not enought arguments"));
	if (tab[3] && tab[4])
		return (ft_error_setenv("", "minishell: setenv: ", " too many arguments"));
	if (ft_strchr(tab[1], '='))
		return (ft_error_setenv(tab[1], "minishell: setenv: '", "' contains a '=' "));
	if ((getenv = get_env(tab[1], shell->env)))
	{
		if (tab[3] && ft_strcmp(tab[3], "1") ==  0)
			modify_env(tab[1], tab[2], &shell);
		ft_strdel(&getenv);
	}
	else
	{
		temp = ft_strjoin(tab[1], "=");
		result = temp;
		temp = ft_strjoin(temp, tab[2]);
		shell->env = ft_tabpushback(shell->env, temp);
		shell->old_env = ft_tabpushback(shell->old_env, temp);
		ft_strdel(&temp);
		ft_strdel(&result);
	}
	return (1);
}
