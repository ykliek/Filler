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

void		read_token(t_map *map, t_token *token)
{
	char	*line;	
	int		height;

	height = 0;
	token->token = (char **)malloc(sizeof(char*) * token->size_h);
	while (height < token->size_h)
	{
		get_next_line(map->fd, &line);
		token->token[height++] = ft_strdup(line);
		ft_strdel(&line);
	}
}

void		read_map(t_map *map)
{
	char	*line;
	int		height;

	get_next_line(map->fd, &line);
	ft_strdel(&line);
	height = 0;
	map->map = (char **)malloc(sizeof(char*) * map->size_h);
	while (height < map->size_h)
	{
		get_next_line(map->fd, &line);
		map->map[height++] = ft_strdup(&line[4]);
		ft_strdel(&line);
	}
}

int		reader(t_map *map, t_token *token, char *line)
{
	if (ft_strncmp("Plateau", line, 6) == 0)
		identify_map_size(map, line);
	if (ft_strncmp("Piece", line, 4) == 0)
	{
		identify_token_size(token, map, line);
		return (1);
	}
	return (0);
}









