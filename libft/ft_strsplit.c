/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 13:36:26 by vmartins          #+#    #+#             */
/*   Updated: 2017/08/22 11:39:17 by vmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char		**tab;
	size_t		temp;
	size_t		i;
	size_t		words;

	if (!s)
		return (NULL);
	i = 0;
	words = ft_words((char *)s, c);
	if (!(tab = (char **)malloc(sizeof(char *) * (words + 1))))
		return (NULL);
	tab[words] = NULL;
	words = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		temp = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > temp)
			tab[words++] = ft_strsub((s + temp), 0, (i - temp));
	}
	return (tab);
}
