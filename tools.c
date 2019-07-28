/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 11:40:04 by ykliek            #+#    #+#             */
/*   Updated: 2019/07/28 11:40:05 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		which_symbol(t_map *map)
{
	if (map->p == 1)
	{
		map->me = ft_strdup("Oo");
		map->enemy = ft_strdup("Xx");
	}
	if (map->p == 2)
	{
		map->me = ft_strdup("Xx");
		map->enemy = ft_strdup("Oo");
	}
}

void	identify_p(t_map *map)
{
	char	*line;

	get_next_line(map->fd, &line);
	if (ft_strncmp("$$$",line, 2) == 0 && map->p == 0)
		map->p = (ft_strstr(line, "p1")) ? 1 : 2;
	ft_strdel(&line);
}

void		free_map(t_map *map)
{
	int		i1;

	i1 = 0;
	while (i1 < map->size_h)
	{
		free(map->map[i1]);
		i1++;
	}
	free(map->map);
}

void		free_token(t_token *token)
{
	int		i1;

	i1 = 0;
	while (i1 < token->size_h)
	{
		free(token->token[i1]);
		i1++;
	}
	free(token->token);
}
