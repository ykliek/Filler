/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 12:02:40 by ykliek            #+#    #+#             */
/*   Updated: 2019/07/28 12:02:41 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	identify_map_size(t_map *map, char *line)
{
	int		count;
	int		time;

	time = 0;
	count = 0;
	while (line[count] != '\0')
	{
		if (line[count] >= '1' && line[count] <= '9' && time != 1)
		{
			map->size_h = ft_atoi(line + count);
			time = 1;
		}
		if (line[count] >= '1' && line[count] <= '9' && time == 1)
			map->size_w = ft_atoi(line + count - 1);
		count++;
	}
	read_map(map);
}

void	identify_token_size(t_token *token, t_map *map, char *line)
{
	int		count;
	int		time;

	time = 0;
	count = 0;
	while (line[count] != '\0')
	{
		if (line[count] >= '1' && line[count] <= '9' && time != 1)
		{
			token->size_h = ft_atoi(line + count);
			time = 1;
		}
		if (line[count] >= '1' && line[count] <= '9' && time == 1)
			token->size_w = ft_atoi(line + count - 1);
		count++;
	}
	read_token(map, token);
}
