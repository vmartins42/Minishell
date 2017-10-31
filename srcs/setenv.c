/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 14:42:59 by vmartins          #+#    #+#             */
/*   Updated: 2017/10/30 11:35:09 by vmartins         ###   ########.fr       */
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

void	ft_setenv_2(char **tab, char *temp, char *result, t_shell *shell)
{
	temp = ft_strjoin(tab[1], "=");
	result = temp;
	temp = ft_strjoin(temp, tab[2]);
	shell->env = ft_tabpushback(shell->env, temp);
	shell->old_env = ft_tabpushback(shell->old_env, temp);
	ft_strdel(&temp);
	ft_strdel(&result);
}

int		ft_setenv(char **tab, t_shell *shell, char *result, char *temp)
{
	char	*getenv;
	char	*e;

	e = "minishell: setenv: ";
	if (!tab[1] || !tab[2])
		return (ft_error_setenv("", e, " not enought args"));
	if (ft_tablen(tab) > 3)
		return (ft_error_setenv("", e, " too many arguments"));
	if (ft_strchr(tab[1], '='))
		return (ft_error_setenv(tab[1], e, " contains a '=' "));
	if ((getenv = get_env(tab[1], shell->env)))
	{
		modify_env(tab[1], tab[2], &shell);
		ft_strdel(&getenv);
	}
	else
		ft_setenv_2(tab, temp, result, shell);
	return (1);
}
