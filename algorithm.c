/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 11:39:51 by ykliek            #+#    #+#             */
/*   Updated: 2019/07/28 11:39:52 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	put_figure(int i1, int i2, t_map *map, t_token *token)
{
	int		t1;
	int		t2;
	int		tmp;

	t1 = 0;
	while (t1 < token->size_h)
	{
		t2 = 0;
		while (token->token[t1][t2] != '\0')
		{
			if (token->token[t1][t2] == '*')
			{
				token->check_x = t1;
				token->check_y = t2;
				tmp = check_all_dots(i1 - t1, i2 - t2, token, map);
				if (token->distance > tmp)
				{
					token->distance = tmp;
					token->ret_x = i1 - t1;
					token->ret_y = i2 - t2;
				}
			}
			t2++;
		}
		t1++;
	}
}

void		algorithm(t_map *map, t_token *token)
{
	int		i1;
	int		i2;

	i1 = 0;
	token->distance = map->size_h * map->size_h + map->size_w * map->size_w;
	while (i1 < map->size_h)
	{
		i2 = 0;
		while (map->map[i1][i2] != '\0')
		{
			if (check_point(i1, i2, map) == 1)
				put_figure(i1, i2, map, token);
			i2++;
		}
		i1++;
	}
	print_result(token);
}