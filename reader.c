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
	char	*name;

	get_next_line(0, &line);
	name = ft_strstr(line, "ykliek");
	if (ft_strncmp("$$$", line, 2) == 0 && map->p == 0)
		map->p = (name) ? 1 : 2;
	ft_strdel(&line);
}

void	identify_size(t_map *map)
{
	char	*line;
	int		count;
	int		time;

	time = 0;
	count = 0;
	get_next_line(0, &line);
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
	ft_strdel(&line);
}

void		read_map(t_map *map)
{
	char	*line;
	int		height;

	identify_p(map);
	identify_size(map);
	get_next_line(0, &line);
	ft_strdel(&line);
	height = 0;
	map->map = (char **)malloc(map->size_h);
	while (height < map->size_h)
	{
		get_next_line(0, &line);
		map->map[height++] = ft_strdup((char *)&line[4]);
		ft_strdel(&line);
	}
}
