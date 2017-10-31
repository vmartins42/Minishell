/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 15:38:20 by vmartins          #+#    #+#             */
/*   Updated: 2017/10/31 15:00:55 by vmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*get_actual(char *elem_tab, char *getenv, t_shell *shell)
{
	char *actual_path;

	if (ft_strcmp(elem_tab, ".") == 0 ||\
		(elem_tab[0] == '.' && elem_tab[1] == '/'))
		actual_path = (getenv) ? ft_strdup(getenv) : ft_getcwd();
	else if (getenv && !(actual_path = back_link(elem_tab, getenv, 0)))
		actual_path = check_link(elem_tab, shell->env);
	else if (!getenv)
		actual_path = ft_getcwd();
	return (actual_path);
}

int		cd_path(char *elem_tab, char *actual_path, t_shell *shell)
{
	char	*pwd;
	char	*oldpwd;
	char	*getenv;
	char	*temp;

	if (check_files(elem_tab))
	{
		ft_strdel(&actual_path);
		return (1);
	}
	chdir(elem_tab);
	getenv = get_env("PWD", shell->env);
	oldpwd = ft_strjoin("OLDPWD=", actual_path);
	cd_adomold(&shell, actual_path, oldpwd);
	temp = ft_removelastslash(elem_tab);
	actual_path = get_actual(temp, getenv, shell);
	pwd = ft_strjoin("PWD=", actual_path);
	cd_adompwd(&shell, actual_path, pwd);
	ft_strdel(&pwd);
	ft_strdel(&oldpwd);
	(getenv) ? ft_strdel(&getenv) : NULL;
	if (elem_tab[ft_strlen(elem_tab) - 1] == '/' ||
		(elem_tab[0] == '/' && !elem_tab[1]))
		ft_strdel(&temp);
	return (1);
}

int		cd_nothing(char *actual_path, t_shell *shell)
{
	char	*pwd;
	char	*oldpwd;
	char	*getenv;

	if (!(getenv = get_env("HOME", shell->env)))
		ft_putstr_fd("minishell: cd: HOME not set\n", 2);
	else
	{
		if (check_files(getenv))
			return (1);
		chdir(getenv);
		pwd = ft_strjoin("PWD=", getenv);
		oldpwd = ft_strjoin("OLDPWD=", actual_path);
		cd_adompwd(&shell, getenv, pwd);
		cd_adomold(&shell, actual_path, oldpwd);
		ft_strdel(&pwd);
		ft_strdel(&oldpwd);
	}
	return (1);
}

int		cd_back(char *actual_path, t_shell *shell)
{
	char	*pwd;
	char	*oldpwd;
	char	*getenv;
	char	*getn;

	if (!(getenv = get_env("OLDPWD", shell->env)))
	{
		ft_strdel(&actual_path);
		return (ft_error_env("", "minishell: ", " cd: OLDPWD not set"));
	}
	oldpwd = getenv;
	if (check_files(oldpwd))
		return (1);
	chdir(oldpwd);
	pwd = ft_strjoin("PWD=", oldpwd);
	if ((getn = get_env("PWD", shell->env)))
		modify_env("PWD", oldpwd, &shell);
	else
		shell->env = ft_tabpushback(shell->env, pwd);
	modify_env("OLDPWD", actual_path, &shell);
	ft_strdel(&pwd);
	ft_strdel(&getenv);
	ft_strdel(&getn);
	ft_strdel(&actual_path);
	return (1);
}

int		ft_cd(char **tab, t_shell *shell, int fast)
{
	char	*getenv;
	char	*actual_path;

	if ((getenv = get_env("PWD", shell->env)))
	{
		actual_path = check_link(getenv, shell->env);
		ft_strdel(&getenv);
	}
	else
		actual_path = ft_getcwd();
	if (fast)
		return (cd_path(tab[0], actual_path, shell));
	if (cd_error(tab))
	{
		ft_strdel(&actual_path);
		return (1);
	}
	if (!tab[1] || ft_strcmp(tab[1], "--") == 0)
		return (cd_nothing(actual_path, shell));
	else if (ft_strcmp(tab[1], "-") == 0)
		return (cd_back(actual_path, shell));
	else
		return (cd_path(tab[1], actual_path, shell));
	ft_strdel(&actual_path);
	return (1);
}
