/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 14:56:53 by ykliek            #+#    #+#             */
/*   Updated: 2019/05/11 14:56:54 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

#include <stdio.h> // DELETE

#include "libft/libft.h"

typedef struct	s_map
{
	char		**map;
	int			size_h;
	int			size_w;
	int			p;
	char		*me;
	char		*enemy;
	int			point_t;
	int			fd;
}				t_map;

typedef	struct	s_token
{
	char		**token;
	int			size_h;
	int			size_w;
	int			ret_x;
	int			ret_y;
	int			distance;
	int			check_x;
	int			check_y;
}				t_token;

void			put_figure(int i1, int i2, t_map *map, t_token *token);

void			algorithm(t_map *map, t_token *token);

int				is_putable(int i1, int i2, t_map *map);

int				check_point(int i1, int i2, t_map *map);

int				check_all_dots(int i1, int i2, t_token *token, t_map *map);

int				find_distance_rev(int i1, int i2, t_map *map);

int				find_distance(int i1, int i2, t_map *map);

void			print_result(t_token *token);

void			read_token(t_map *map, t_token *token);

void			identify_map_size(t_map *map, char *line);

void			identify_token_size(t_token *token, t_map *map, char *line);

int				reader(t_map *map, t_token *token, char *line);

void			which_symbol(t_map *map);

void			identify_p(t_map *map);

void			read_map(t_map *map);

void			free_token(t_token *token);

void			free_map(t_map *map);

#endif
