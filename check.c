/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 11:41:58 by ykliek            #+#    #+#             */
/*   Updated: 2019/07/28 11:42:01 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		is_putable(int i1, int i2, t_map *map)
{
	if (i1 < 0 || i1 >= map->size_h || i2 < 0 || i2 >= map->size_w)
		return (0);
	if (map->map[i1][i2] == map->me[0] || map->map[i1][i2] == map->me[1]
		|| map->map[i1][i2] == map->enemy[0] 
		|| map->map[i1][i2] == map->enemy[1])
		return (0);
	return (1);
}

int		check_point(int i1, int i2, t_map *map)
{
	if (i1 > 0)
		if ((map->map[i1][i2] == map->me[0] && map->map[i1 - 1][i2] == '.') ||
			(map->map[i1][i2] == map->me[1] && map->map[i1 - 1][i2] == '.'))
			return (1);
	if (i1 < (map->size_h - 1))
		if ((map->map[i1][i2] == map->me[0] && map->map[i1 + 1][i2] == '.') ||
			(map->map[i1][i2] == map->me[1] && map->map[i1 + 1][i2] == '.'))
			return (1);
	if (i2 > 0)
		if ((map->map[i1][i2] == map->me[0] && map->map[i1][i2 - 1] == '.') ||
			(map->map[i1][i2] == map->me[1] && map->map[i1][i2 - 1] == '.'))
			return (1);
	if (i2 < (map->size_w - 1))
		if ((map->map[i1][i2] == map->me[0] && map->map[i1][i2 + 1] == '.') ||
			(map->map[i1][i2] == map->me[1] && map->map[i1][i2 + 1] == '.'))
			return (1);
	return (0);

}

int		check_all_dots(int i1, int i2, t_token *token, t_map *map)
{
	int		c1;
	int		c2;
	int		distance;
	int		tmp;

	distance = map->size_h * map->size_h + map->size_w * map->size_w;
	c1 = 0;
	while (c1 < token->size_h)
	{
		c2 = 0;
		while (token->token[c1][c2] != '\0')
		{
			if (token->token[c1][c2] == '*')
			{
					if (is_putable(c1 + i1, c2 + i2, map) == 0)
					{
						if (c1 == token->check_x && c2 == token->check_y)
							tmp = 0;
						else
							return (token->distance);
					}
				tmp = find_distance(c1 + i1, c2 + i2, map);
				distance = distance > tmp ? tmp : distance;
			}
			c2++;
		}
		c1++;
	}
	return (distance);
}
