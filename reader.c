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

void		which_symbol(t_map *map)
{
	if (map->p == 1)
	{
		map->me = ft_strdup("Oo");
		map->me = ft_strdup("Xx");
	}
	if (map->p == 0)
	{
		map->me = ft_strdup("Xx");
		map->me = ft_strdup("Oo");
	}
}

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

void	identify_ship_size(t_map *map, t_token *ship)
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

void		read_token(t_map *map, t_token *token)
{
	char	*line;	
	int		height;

	height = 0;
	identify_ship_size(map, token);
	token->token = (char **)malloc(token->size_h);
	while (height < token->size_h)
	{
		get_next_line(map->fd, &line);
		token->token[height++] = ft_strdup(line);
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
		map->map[height++] = ft_strdup(&line[4]);
		height++;
		free(line);
	}
}

void		reader(t_map *map, t_token *token)
{
	char	*line;

	while (get_next_line(map->fd, &line) > 0)
	{
		if (ft_strncmp("Plateau", line, 6) == 0)
		{
			read_map(map);
			ft_strdel(&line);
		}
		if (ft_strncmp("Piece", line, 4) == 0)
		{
			read_token(map, token);
			ft_strdel(&line);
		}
		else
			ft_strdel(&line);
	}
}









