/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 11:41:34 by ykliek            #+#    #+#             */
/*   Updated: 2019/07/28 11:41:35 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		find_distance_rev(int i1, int i2, t_map *map)
{
	int		t1;
	int		t2;
	int		distance;
	int		tmp;

	distance = map->size_h * map->size_h + map->size_w * map->size_w;
	tmp = 0;
	t1 = i1;
	t2 = i2;
	while (i1 >= 0)
	{
		while (i2 >= 0)
		{
			if (map->map[i1][i2] == map->enemy[0]
				|| map->map[i1][i2] == map->enemy[1])
			{
				tmp = (i1 - t1) * (i1 - t1) + (i2 - t2) * (i2 - t2);
				distance = (distance > tmp) ? tmp : distance;
			}
			i2--;
		}
		i2 = (map->size_w - 1);
		i1--;
	}
	return (distance);
}

int		find_distance(int i1, int i2, t_map *map)
{
	int 	t1;
	int		t2;
	int		distance;
	int		rev_distance;
	int		tmp;

	t1 = i1;
	t2 = i2;
	distance = map->size_h * map->size_h + map->size_w * map->size_w;
	rev_distance = map->size_h * map->size_h + map->size_w * map->size_w;
	while (i1 < map->size_h)
	{
		while (map->map[i1][i2] != '\0')
		{
			if (map->map[i1][i2] == map->enemy[0]
				|| map->map[i1][i2] == map->enemy[1])
			{
				tmp = (i1 - t1) * (i1 - t1) + (i2 - t2) * (i2 - t2);
				distance = (distance > tmp) ? tmp : distance;
			}
			i2++;
		}
		i2 = 0;
		i1++;
	}
	rev_distance = find_distance_rev(t1, t2, map);
	distance = (distance > rev_distance) ? rev_distance : distance;
	return (distance);
}
