/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_triplejoin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 13:55:42 by vmartins          #+#    #+#             */
/*   Updated: 2017/10/10 15:49:30 by vmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_triplejoin(char *s1, char *s2)
{
	char	*temp;
	char	*tmp;

	if (!s1 || !s2)
		return (NULL);
	temp = ft_strjoin(s1, "/");
	tmp = temp;
	temp = ft_strjoin(temp, s2);
	ft_strdel(&tmp);
	return (temp);
}
