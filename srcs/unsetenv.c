/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 13:14:30 by vmartins          #+#    #+#             */
/*   Updated: 2017/10/30 15:09:00 by vmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_supp_lig_tab2(t_shell *shell, int position_elem)
{
	int		i;
	int		j;
	char	**new_env;

	i = -1;
	j = 0;
	new_env = NULL;
	if ((new_env = (char **)malloc(sizeof(*new_env) * \
					(ft_tablen(shell->env) + 1))) == NULL)
		exit(1);
	while (shell->env[++i])
	{
		if (i != position_elem)
		{
			new_env[j] = ft_strdup(shell->env[i]);
			j++;
		}
	}
	new_env[j] = NULL;
	ft_freetab((void**)shell->env, ft_tablen(shell->env));
	ft_freetab((void**)shell->old_env, ft_tablen(shell->old_env));
	shell->env = ft_tabdup(new_env);
	shell->old_env = ft_tabdup(new_env);
	ft_freetab((void**)new_env, ft_tablen(new_env));
}

int		ft_unsetenv(char **tab, t_shell *shell, int j)
{
	int		i;
	char	**var;
	char	*e;

	e = "unsetenv: ";
	if (!tab[1])
		return (ft_error_setenv("", e, " not enought arguments"));
	while (tab[++j])
	{
		i = -1;
		var = NULL;
		while (shell->env[++i])
		{
			var = ft_strsplit(shell->env[i], '=');
			if (var && ft_strcmp(var[0], tab[j]) == 0)
			{
				ft_supp_lig_tab2(shell, i);
				ft_freetab((void**)var, ft_tablen(var));
				break ;
			}
			ft_freetab((void**)var, ft_tablen(var));
		}
	}
	return (1);
}
