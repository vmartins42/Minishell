/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 13:14:30 by vmartins          #+#    #+#             */
/*   Updated: 2017/09/20 13:48:52 by vmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void		ft_supp_lig_tab(t_shell *shell, int position_elem)
{
	int		i;
	char	**new_env;

	i = -1;
	new_env = NULL;
	while (shell->env[++i])
	{
		if (i != position_elem)
			new_env = ft_tabpushback(new_env, shell->env[i]);
	}
	ft_freetab((void**)shell->env, ft_tablen(shell->env));
	shell->env = ft_tabdup(new_env);
	shell->old_env = ft_tabdup(new_env);
}

int		ft_unsetenv(char **tab, t_shell *shell)
{
	int		i;
	int		j;
	char	**var;

	j = -1;
	if (!tab[1])
		return (ft_error_setenv("", "minishell: unsetenv: ", " not enought arguments"));
	while(tab[++j])
	{
		i = -1;
		while (shell->env[++i])
		{
			var = ft_strsplit(shell->env[i], '=');
			if (var && ft_strcmp(var[0], tab[j]) == 0)
			{
			ft_supp_lig_tab(shell, i);
				ft_freetab((void**)var, ft_tablen(var));
			break;
			}
		}
	}
	return (1);
}
