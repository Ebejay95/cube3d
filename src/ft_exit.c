/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 12:11:27 by ajehle            #+#    #+#             */
/*   Updated: 2024/09/23 09:08:06 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	call_exit_minimap(t_mini *minimap)
{
	if (minimap)
	{
		free(minimap);
	}
}

void	call_exit_map_textrs(t_game *game, t_map *map)
{
	if (map->tex_west)
		mlx_delete_texture(map->tex_west);
	if (map->tex_east)
		mlx_delete_texture(map->tex_east);
	if (map->tex_north)
		mlx_delete_texture(map->tex_north);
	if (map->tex_south)
		mlx_delete_texture(map->tex_south);
	if (map->img_west)
		mlx_delete_image(game->mlx, map->img_west);
	if (map->img_east)
		mlx_delete_image(game->mlx, map->img_east);
	if (map->img_north)
		mlx_delete_image(game->mlx, map->img_north);
	if (map->img_south)
		mlx_delete_image(game->mlx, map->img_south);
	map->tex_west = NULL;
	map->tex_east = NULL;
	map->tex_north = NULL;
	map->tex_south = NULL;
	map->img_west = NULL;
	map->img_east = NULL;
	map->img_north = NULL;
	map->img_south = NULL;
}

void	call_exit_map(t_game *game)
{
	int	i;

	i = 0;
	if (game)
	{
		if (game->map)
		{
			if (game->map->content)
			{
				while (game->map->content[i])
				{
					free(game->map->content[i]);
					game->map->content[i] = NULL;
					i++;
				}
				free(game->map->content);
				game->map->content = NULL;
			}
			call_exit_map_textrs(game, game->map);
			free(game->map);
			game->map = NULL;
		}
	}
}

void	call_exit(t_game *game)
{
	if (game)
	{
		call_exit_map(game);
		call_exit_minimap(game->minimap);
		game = NULL;
	}
}
