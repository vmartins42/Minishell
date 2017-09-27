/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 11:37:38 by vmartins          #+#    #+#             */
/*   Updated: 2017/09/05 11:50:56 by vmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_exit(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	if (i == 2)
		exit(ft_atoi(args[1]));
	if (i > 2)
		ft_putendl_fd("exit: too many arguments", 2);
	else
		exit(0);
}
