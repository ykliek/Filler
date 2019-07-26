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

typedef struct s_point
{
	int		x;
	int		y;
}				t_point;

typedef struct	s_map
{
	char		**map;
	int			size_h;
	int			size_w;
	int			p;
	char		*me;
	char		*enemy;
	int			my_pos_x;
	int			my_pos_y;
	int			enemy_pos_x;
	int			enemy_pos_y;
	int			point_t;
	int			fd;
}				t_map;

typedef	struct	s_token
{
	char		**token;
	int			size_h;
	int			size_w;
	int			points;
}				t_token;

void			reader(t_map *map, t_token *token);

void			identify_p(t_map	*map);

#endif

// while [ 1 ]; do sleep 1 ; clear ; ./ykliek.filler test; done