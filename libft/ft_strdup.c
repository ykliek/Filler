/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 13:52:55 by ykliek            #+#    #+#             */
/*   Updated: 2018/10/26 13:52:57 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	int		size;
	char	*dup;

	i = 0;
	if (src == NULL)
		return (NULL);
	size = (int)ft_strlen(src) + 1;
	if (!(dup = (char*)malloc(sizeof(char) * size)))
		return (0);
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
