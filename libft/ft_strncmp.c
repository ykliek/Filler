/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 14:26:08 by ykliek            #+#    #+#             */
/*   Updated: 2018/10/28 14:26:09 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		cmp(unsigned char *str1, unsigned char *str2, int n)
{
	int		count_1;

	count_1 = 0;
	while (count_1 != (int)n)
	{
		if (str1[count_1] == str2[count_1] && count_1 == (int) n)
			return (0);
		if (str1[count_1] == str2[count_1] && str2[count_1] == '\0')
			return (0);
		if (str1[count_1] > str2[count_1] && str1 && str2)
			return (str1[count_1] - str2[count_1]);
		if (str1[count_1] < str2[count_1])
			return (str1[count_1] - str2[count_1]);
		if (count_1 == (int) n && count_1 != (int) n)
			return (str1[count_1] - str2[count_1]);
		if (count_1 != (int) n && count_1 == (int) n)
			return (str1[count_1] - str2[count_1]);
		count_1++;
	}
	return (0);
}

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	if (s1 && s2)
	{
		str1 = (unsigned char *) s1;
		str2 = (unsigned char *) s2;
		return (cmp(str1, str2, (int)n));
	}
	return (1);
}
