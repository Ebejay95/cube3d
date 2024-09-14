/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 12:11:10 by ajehle            #+#    #+#             */
/*   Updated: 2024/09/14 12:26:33 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"


int	start_minimap(t_game *game, t_map *map)
{

	game->minimap = ft_initialize_minimap(map);
	if (!game->minimap)
		return (1);
	game->minimap->pos = get_pos_unique(map->map_as_arr, 'P');
	if (!game->minimap->pos)
		return (1);
	game->minimap->delta =  ft_calloc(1, sizeof(t_delta));
	if (!game->minimap->delta)
		return (1);
	game->minimap->delta->x = 0;
	game->minimap->delta->y = 0;
	game->minimap->delta->a = 0;
	game->minimap->overlay = NULL;
	return (0);
}

t_mini	*ft_initialize_minimap(t_map* map)
{
	t_mini	*minimap;

	minimap = NULL;
	minimap = ft_calloc(sizeof(t_mini), 1);
	if (minimap)
	{
		minimap->image = NULL;
		minimap->img_dir = NULL;
		minimap->overlay = NULL;
		minimap->pos = NULL;
		minimap->delta = NULL;
	}
	return (minimap);
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
	game->game_mlx = NULL;
	game->frame = 0;
	return (game);
}

t_map	*ft_initialize_map(char* string)
{
	t_map*	map;

	map = NULL;
	map = ft_calloc(sizeof(t_map), 1);
	if (!map)
		return (NULL);
	map->map_as_string = string;
	map->map_as_arr = ft_split(map->map_as_string, '\n');
	map->width = 1000;
	map->height = 650;
	print_2d_arr(map->map_as_arr);

	return (map);
}

t_mini	*ft_initialize_mini(void)
{
	t_mini*	mini;

	mini = NULL;
	mini = ft_calloc(sizeof(t_mini), 1);
	if (!mini)
		return (NULL);
	return (mini);
}

mlx_t	*ft_init_window(t_game *game)
{
	// game->map->width = ft_strlen(game->map->map_as_arr[0]) * PIXEL;
	// game->map->height = get_height(game->map->map_as_arr) * PIXEL;
	game->game_mlx = mlx_init(game->map->width, game->map->height,
			NAME_WINDOW, true);
	if (!game->game_mlx)
		return (NULL);
	return (game->game_mlx);
}
t_game	*ft_init(t_map *map, t_mini* mini)
{
	// t_game	*game;


	// if (!game)
	// 	return (NULL);
	// if (start_minimap(game, map))
	// 	return (ft_printf("Error\n"), call_exit(game), NULL);
	// if (!ft_init_window(game))
	// 	return (ft_printf("Error\n"), call_exit(game), NULL);
	// return (game);
}
