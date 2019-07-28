/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 14:56:44 by ykliek            #+#    #+#             */
/*   Updated: 2019/07/28 19:31:30 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		print_result(t_token *token)
{
	ft_putnbr(token->ret_x);
	ft_putchar(' ');
	ft_putnbr(token->ret_y);
	ft_putchar('\n');
}

void		init_struct(t_map *map, t_token *token)
{
	map->size_h = 0;
	map->size_w = 0;
	map->p = 0;
	token->size_h = 0;
	token->size_w = 0;
	token->ret_x = 0;
	token->ret_y = 0;
	token->distance = 0;
	token->check_x = 0;
	token->check_y = 0;
}

int		main()
{
	t_map	map;
	t_token	token;
	char	*line;

	map.fd = 0;
	init_struct(&map, &token);
	identify_p(&map);
	which_symbol(&map);
	while (get_next_line(map.fd, &line) > 0)
	{
		if (reader(&map, &token, line) == 1)
		{
			algorithm(&map, &token);
			free_map(&map);
			free_token(&token);
		}
		ft_strdel(&line);
	}
	return (0);
}


// int		main(int argc, char **argv)
// {
// 	t_map	map;
// 	t_token	token;

// 	argc = 0;
// 	map.fd =  open(argv[1], O_RDONLY);
// 	init_map(&map, &token);
// 	identify_p(&map);
// 	which_symbol(&map);
// 	reader(&map, &token);
// 	algorithm(&map, &token);
// 	print_result(&token);
// 	return (0);
// }
