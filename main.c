/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 14:56:44 by ykliek            #+#    #+#             */
/*   Updated: 2019/05/11 14:56:45 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "filler.h"

void		init_map(t_map *map)
{
	map->size_h = 0;
	map->size_w = 0;
	map->p = 0;
	map->my_pos_x = 0;
	map->my_pos_y = 0;
	map->enemy_pos_x = 0;
	map->enemy_pos_y = 0;
}

int		main(void)
{
	t_map	map;

	init_map(&map);
	read_map(&map);
	printf("%d %d\n", map.p, map.size_w);
	return (0);
}