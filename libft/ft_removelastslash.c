/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_removelastslash.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 15:36:28 by vmartins          #+#    #+#             */
/*   Updated: 2017/10/10 11:16:27 by vmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_removelastslash(char *str)
{
	char	*result;
	int		len;

	result = NULL;
	len = ft_strlen(str);
	if (str[len - 1] == '/' && !str[len])
	{
		while (str[len - 1] == '/')
			len--;
		result = ft_strsub(str, 0, len);
		return (result);
	}
	return (str);
}
