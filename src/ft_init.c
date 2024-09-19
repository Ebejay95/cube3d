/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 12:11:10 by ajehle            #+#    #+#             */
/*   Updated: 2024/09/19 15:31:47 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"


mlx_t	*ft_init_window(t_game *game)
{
	game->mlx = mlx_init(game->map->width, game->map->height,
			NAME_WINDOW, true);
	if (!game->mlx)
		return (NULL);
	return (game->mlx);
}


t_mini*	ft_initialize_minimap(void)
{
	t_mini*	mini;

	mini = NULL;
	mini = ft_calloc(sizeof(t_mini), 1);
	if (!mini)
		return (NULL);
	mini->image = NULL;
	mini->img_dir = NULL;
	mini->overlay = NULL;
	mini->pos_x = 0;
	mini->pos_y = 0;
	mini->delta_x = 0;
	mini->delta_y = 0;
	mini->angle = 0;
	mini->px_height = 100;
	mini->px_width = 200;
	mini->map_height = 8;
	mini->map_width = 9;
	return (mini);
}

t_map	*ft_initialize_map(char** map_in)
{
	t_map*	map;

	map = NULL;
	map = ft_calloc(sizeof(t_map), 1);
	if (!map)
		return (NULL);
	map->map_as_arr = map_in;
	map->width = 1000;
	map->height = 650;
	print_2d_arr(map->map_as_arr);

	return (map);
}

t_game	*ft_initialize_game(void)
{
	t_game	*game;

	game = NULL;
	game = ft_calloc(sizeof(t_game), 1);
	if (!game)
		return (NULL);
	game->map = NULL;
	game->minimap = NULL;
	game->mlx = NULL;
	return (game);
}

t_game* ft_initialize(t_map	*map_in)
{
	t_game	*game;

	if (!map_in)
		return (NULL);
	game = ft_initialize_game();
	if(!game)
		return (ft_printf("Error\n"), call_exit(game), NULL);
	game->map = ft_initialize_map(map_in);
	if(!game->map)
		return (ft_printf("Error\n"), call_exit(game), NULL);
	game->minimap = ft_initialize_minimap();
	if(!game->minimap)
		return (ft_printf("Error\n"), call_exit(game), NULL);
	return	game;
}
