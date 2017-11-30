/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 15:38:20 by vmartins          #+#    #+#             */
/*   Updated: 2017/11/30 12:36:13 by vmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void		ft_cd_basic(t_shell *shell, char *path)
{
	char	*curpath;
	char	*pwd;

	pwd = ft_getcwd();
	if (path[0] == '/')
		curpath = ft_strdup(path);
	else
	{
		curpath = ft_strjoin(pwd, "/");
		curpath = ft_replace_str(ft_strjoin(curpath, path), curpath);
	}
	curpath = ft_replace_str(ft_remove_useless_path(curpath), curpath);
	if (check_files(path))
	{
		free(curpath);
		free(pwd);
		return ;
	}
	chdir(curpath);
	free(curpath);
	replace_pwd(&shell, pwd);
	replace_oldpwd(&shell, pwd);
}

void		swap_pwd(t_shell *shell)
{
	char	*oldpwd;

	if ((oldpwd = get_env("OLDPWD", shell->env)) == NULL)
	{
		ft_error_env("", "cd: OLDPWD not set", "");
		return ;
	}
	ft_cd_basic(shell, oldpwd);
	free(oldpwd);
}

void		go_home(t_shell *shell)
{
	char	*home;

	if ((home = get_env("HOME", shell->env)) == NULL)
	{
		ft_error_env("", "cd: HOME not set", "");
		return ;
	}
	ft_cd_basic(shell, home);
	free(home);
}

void		ft_cd(char **tab, t_shell *shell, int fast)
{
	if (fast == 1)
	{
		ft_cd_basic(shell, tab[0]);
		return ;
	}
	if (cd_error(tab))
		return ;
	else if (!tab[1])
		go_home(shell);
	else if (ft_strcmp(tab[1], "-") == 0)
		swap_pwd(shell);
	else
		ft_cd_basic(shell, tab[1]);
}
