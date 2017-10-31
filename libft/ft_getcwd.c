/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getcwd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 14:36:52 by vmartins          #+#    #+#             */
/*   Updated: 2017/10/27 13:55:52 by vmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_getcwd(void)
{
	char	*temp;
	char	path[254];

	ft_memset(path, 0, sizeof(path));
	getcwd(path, sizeof(path));
	temp = ft_strdup(path);
	return (temp);
}
