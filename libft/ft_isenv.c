/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 11:31:22 by vmartins          #+#    #+#             */
/*   Updated: 2017/09/13 11:33:41 by vmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isenv(char *env_line, char *name)
{
	int		i;

	i = 0;
	while (env_line[i] == name[i])
		i++;
	if (env_line[i] == '=' && !name[i])
		return (1);
	else
		return (0);
}
