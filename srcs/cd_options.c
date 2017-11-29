/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_options.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 15:23:16 by vmartins          #+#    #+#             */
/*   Updated: 2017/11/29 17:59:09 by vmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		cd_fast(char **tab, t_shell *shell)
{
	DIR		*dir;

	if ((dir = opendir(tab[0])))
	{
		closedir(dir);
		ft_cd(tab, shell, 1);
	}
	return (0);
}
