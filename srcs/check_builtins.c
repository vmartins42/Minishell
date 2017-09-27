/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builtins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 11:54:59 by vmartins          #+#    #+#             */
/*   Updated: 2017/09/26 14:53:27 by vmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*int		is_builtin(char *elem_tab)
{
	if (elem_tab == '\0')
		return (0);
	else if (!ft_strcmp(elem_tab, "exit"))
		return(1);
	else if (!ft_strcmp(elem_tab, "env"))
		return (1);
	else if (!ft_strcmp(elem_tab, "unsetenv"))
		return (1);
	else if (!ft_strcmp(elem_tab, "echo"))
		return (1);
	else if (!ft_strcmp(elem_tab, "cd"))
		return (1);
	else if (!ft_strcmp(elem_tab, "setenv"))
		return (1);
	return (0);
}*/

/*int		process(char **tab, t_shell *shell)
{
	pid_t	dad;

	if (ft_)
}*/

int		check_builtin(char **tab, t_shell *shell, int i)
{
	(void)i;
	if (!tab[0])
		return (1);
	if (ft_strcmp(tab[0], "exit") == 0)
		return (0);
	else if (ft_strcmp(tab[0], "env") == 0)
		return (ft_env(tab, shell));
	else if (ft_strcmp(tab[0], "unsetenv") == 0)
		return (ft_unsetenv(tab, shell));
	else if (ft_strcmp(tab[0], "echo") == 0)
		return (ft_echo(tab, shell));
	else if (ft_strcmp(tab[0], "cd") == 0)
		return (ft_cd(tab, shell, 0));
	else if (ft_strcmp(tab[0], "setenv") == 0)
		return (ft_setenv(tab, shell, NULL, NULL));
	return (1);
}
