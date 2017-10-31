/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_modify.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 11:27:30 by vmartins          #+#    #+#             */
/*   Updated: 2017/10/16 15:15:38 by vmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	cd_adomold(t_shell **beginshell, char *actual_path, char *name)
{
	char	*getenv;
	t_shell *shell;

	shell = *beginshell;
	if ((getenv = get_env("OLDPWD", shell->env)))
		modify_env("OLDPWD", actual_path, &shell);
	else
		shell->env = ft_tabpushback(shell->env, name);
	ft_strdel(&getenv);
	ft_strdel(&actual_path);
}

void	cd_adompwd(t_shell **beginshell, char *actual_path, char *name)
{
	char	*getenv;
	t_shell	*shell;

	shell = *beginshell;
	if ((getenv = get_env("PWD", shell->env)))
		modify_env("PWD", actual_path, &shell);
	else
		shell->env = ft_tabpushback(shell->env, name);
	ft_strdel(&getenv);
	ft_strdel(&actual_path);
}

int		check_files(char *elem_tab)
{
	struct stat	sb;

	lstat(elem_tab, &sb);
	if (!S_ISDIR(sb.st_mode) && !S_ISREG(sb.st_mode) \
			&& !S_ISLNK(sb.st_mode))
	{
		return (ft_error_env(elem_tab, "cd: ", \
			" Not such file or directory: "));
	}
	if (!S_ISDIR(sb.st_mode) && !S_ISLNK(sb.st_mode))
		return (ft_error_env(elem_tab, "cd: ", " Not a directory"));
	else if (access(elem_tab, R_OK) && S_ISDIR(sb.st_mode))
		return (ft_error_env(elem_tab, "cd: ", " permission denied"));
	return (0);
}
