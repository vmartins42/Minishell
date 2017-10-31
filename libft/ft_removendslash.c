/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_removendslash.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 11:19:31 by vmartins          #+#    #+#             */
/*   Updated: 2017/10/10 11:22:51 by vmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_removendslash(char *str)
{
	char	*result;
	int		len;

	len = ft_strlen(str);
	while (str[len] != '/')
		len--;
	result = ft_strsub(str, 0, len);
	return (result);
}
