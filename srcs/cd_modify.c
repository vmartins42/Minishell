/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_modify.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 11:27:30 by vmartins          #+#    #+#             */
/*   Updated: 2017/11/29 17:57:50 by vmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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
