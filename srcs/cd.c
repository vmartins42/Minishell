/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 15:38:20 by vmartins          #+#    #+#             */
/*   Updated: 2017/09/26 15:10:22 by vmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		ft_cd(char **tab, t_shell *shell, int fast)
{
	char	*getenv;
	char	*actual_path;
	int		i;

	if ((getenv = get_env("PWD", shell->env)))
	{
		actual_path = 
	}
/*	int		i;
	char	*pwd;
	char	dir[256];
	char	*oldpwd;

	i = -1;
	if (ft_tablen(tab) > 2)
	{
		ft_putendl("trop darg");
		return (1);
	}
	if (tab[0] && !tab[1])// parse cd seul
	{
		pwd = get_env("HOME", shell->env);
		
	}

	else if (tab[0] && tab[1])
	{
		if (tab[1][0] == '-' && ft_strlen(tab[1]) == 1)
		{
			if ((oldpwd = get_env("OLDPWD", shell->env)) != NULL)
			{	
				if (chdir(oldpwd) == 0)
				{
					pwd = get_env("PWD", shell->env);
					modify_env("OLDPWD", pwd, &shell);
					modify_env("PWD", getcwd(dir, sizeof(dir)), &shell);
					free(pwd);
				}
				free(oldpwd);
			}
		}
		else
		{
			if (chdir(tab[1]) == 0)
			{
				pwd = get_env("PWD", shell->env);
				modify_env("OLDPWD", pwd, &shell);
				modify_env("PWD", getcwd(dir, sizeof(dir)), &shell);
				free(pwd);
			}
		}
	}
	free le retour des getenv*/
	return(1);
}
