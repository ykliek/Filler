/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 22:04:34 by ykliek            #+#    #+#             */
/*   Updated: 2019/07/27 22:04:37 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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

void		print_result(t_token *token)
{
	ft_putnbr(token->ret_x);
	ft_putchar(' ');
	ft_putnbr(token->ret_y);
	ft_putchar('\n');
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
			// if (i1 == 12 && i2 == 8)
			// 	printf("sdf");
			if (check_point(i1, i2, map) == 1)
			{
				put_figure(i1, i2, map, token);
			}
			i2++;
		}
		i1++;
	}
	print_result(token);
}
