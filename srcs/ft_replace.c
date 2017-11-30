/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 13:13:34 by vmartins          #+#    #+#             */
/*   Updated: 2017/11/30 11:59:20 by vmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void			replace_oldpwd(t_shell **beginshell, char *pwd)
{
	char	*getenv;
	char	*tmp;
	t_shell	*shell;

	shell = *beginshell;
	if ((getenv = get_env("OLDPWD", shell->env)))
		modify_env("OLDPWD", pwd, &shell);
	else
	{
		tmp = ft_strjoin("OLDPWD=", pwd);
		shell->env = ft_tabpushback(shell->env, tmp);
		free(tmp);
	}
	free(getenv);
	free(pwd);
}

void			replace_pwd(t_shell **beginshell, char *pwd)
{
	char	*getenv;
	char	*tmp;
	t_shell	*shell;

	shell = *beginshell;
	pwd = ft_getcwd();
	if ((getenv = get_env("PWD", shell->env)))
		modify_env("PWD", pwd, &shell);
	else
	{
		tmp = ft_strjoin("PWD=", pwd);
		shell->env = ft_tabpushback(shell->env, tmp);
		free(tmp);
	}
	free(getenv);
	free(pwd);
}

char			*ft_replace_str(char *new_str, char *old)
{
	if (old)
		free(old);
	return (new_str);
}
