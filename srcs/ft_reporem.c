/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 13:13:34 by vmartins          #+#    #+#             */
/*   Updated: 2017/11/29 17:52:46 by vmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char		*add_path(char *str1, char *str2)
{
	char	*ret;
	char	*tmp;

	ret = ft_strdup("/");
	tmp = ret;
	ret = ft_strjoin(ret, str2);
	free(tmp);
	if (str1)
	{
		tmp = ret;
		ret = ft_strjoin(str1, ret);
		free(tmp);
		free (str1);
	}
	return (ret);
}

static char		*split_to_path(char **split)
{
	char	*ret;
	int		i;

	i = 0;
	ret = NULL;
	while (split[i])
	{
		if (ft_strcmp(split[i], "."))
			ret = add_path(ret, split[i]);
		i++;
	}
	return (ret == NULL) ? (ft_strdup("/")) : (ret);
}

char			*ft_remove_useless_path(char *str)
{
	char	*ret;
	char	**split;
	int		i;

	i = 0;
	split = ft_strsplit(str, '/');
	while (split[i])
	{
		if (!ft_strcmp(split[i], ".."))
		{
			free(split[i]);
			split[i] = ft_strdup(".");
			while (!ft_strcmp(split[i], ".") && i > 0)
				i--;
			free(split[i]);
			split[i] = ft_strdup(".");
		}
		else
			i++;
	}
	ret = split_to_path(split);
	ft_freetab((void**)split, ft_tablen(split));
	return (ret);
}

void	replace_pwd(t_shell **beginshell, char *pwd)
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
	//ft_strdel(&getenv);
	//ft_strdel(&pwd);
	free(getenv);
	free(pwd);
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
	//ft_strdel(&getenv);
	//ft_strdel(&pwd);
}

char	*ft_replace_str(char *new_str, char *old)
{
	if (old)
		free(old);
	return (new_str);
}
