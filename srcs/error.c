/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 16:24:18 by vmartins          #+#    #+#             */
/*   Updated: 2017/10/27 13:18:54 by vmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		cd_error(char **tab)
{
	if (ft_tablen(tab) > 3)
		return (ft_error_env("", "cd: ", " too many arguments"));
	return (0);
}

int		ft_error_setenv(char *elem_tab, char *name, char *error)
{
	ft_putstr_fd(name, 2);
	ft_putstr_fd(elem_tab, 2);
	ft_putstr_fd(error, 2);
	ft_putstr_fd("\n", 2);
	return (1);
}

int		ft_error_env(char *elem_tab, char *name, char *error)
{
	ft_putstr_fd(name, 2);
	ft_putstr_fd(error, 2);
	ft_putstr_fd(elem_tab, 2);
	ft_putstr_fd("\n", 2);
	return (1);
}
