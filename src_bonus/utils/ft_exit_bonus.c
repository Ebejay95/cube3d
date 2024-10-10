/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 23:58:14 by jeberle           #+#    #+#             */
/*   Updated: 2024/10/10 14:28:48 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/cub3d_bonus.h"

void	call_exit_map_textrs(t_game *game)
{
	if (game->map->tex_west)
		mlx_delete_texture(game->map->tex_west);
	if (game->map->tex_east)
		mlx_delete_texture(game->map->tex_east);
	if (game->map->tex_north)
		mlx_delete_texture(game->map->tex_north);
	if (game->map->tex_south)
		mlx_delete_texture(game->map->tex_south);
	if (game->map->tex_door)
		mlx_delete_texture(game->map->tex_door);
	game->map->tex_west = NULL;
	game->map->tex_east = NULL;
	game->map->tex_north = NULL;
	game->map->tex_south = NULL;
	game->map->tex_door = NULL;
}

void	call_exit_player(t_player *player)
{
	if (player)
		free(player);
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
			call_exit_map_textrs(game);
			free(game->map);
			game->map = NULL;
		}
	}
}

void	call_exit(t_game *game)
{
	if (game)
	{
		if (game->music_thread != NULL)
		{
			if (game->music_pid > 0)
				kill(game->music_pid, SIGKILL);
			pthread_join(game->music_thread, NULL);
			game->music_thread = NULL;
		}
		call_exit_player(game->player);
		call_exit_map(game);
	}
}
