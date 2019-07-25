/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 09:22:17 by ykliek            #+#    #+#             */
/*   Updated: 2019/07/24 09:22:23 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	identify_p(t_map	*map)
{
	char	*line;

	get_next_line(map->fd, &line);
	if (ft_strncmp("$$$", line, 2) == 0 && map->p == 0)
		map->p = (ft_strstr(line, "ykliek")) ? 1 : 2;
	free(line);
}

void	identify_map_size(t_map *map)
{
	char	*line;
	int		count;
	int		time;

	time = 0;
	count = 0;
	get_next_line(map->fd, &line);
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
	free(line);
}

void	identify_ship_size(t_map *map, t_ship *ship)
{
	char	*line;
	int		count;
	int		time;

	time = 0;
	count = 0;
	get_next_line(map->fd, &line);
	while (line[count] != '\0')
	{
		if (line[count] >= '1' && line[count] <= '9' && time != 1)
		{
			ship->size_h = ft_atoi(line + count);
			time = 1;
		}
		if (line[count] >= '1' && line[count] <= '9' && time == 1)
			ship->size_w = ft_atoi(line + count - 1);
		count++;
	}
	free(line);
}

void		read_ship(t_map *map, t_ship *ship)
{
	char	*line;	
	int		height;

	height = 0;
	identify_ship_size(map, ship);
	ship->ship = (char **)malloc(ship->size_h);
	while (height < ship->size_h)
	{
		get_next_line(map->fd, &line);
		ship->ship[height++] = ft_strdup(line);
		free(line);
	}
}

void		read_map(t_map *map)
{
	char	*line;
	int		height;

	identify_p(map);
	identify_map_size(map);
	get_next_line(map->fd, &line);
	free(line);
	height = 0;
	map->map = (char **)malloc(map->size_h);
	while (height < map->size_h)
	{
		get_next_line(map->fd, &line);
		map->map[height++] = ft_strjoin(line, "\0");
		height++;
		free(line);
	}
}
