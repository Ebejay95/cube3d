/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 12:11:27 by ajehle            #+#    #+#             */
/*   Updated: 2024/09/14 12:11:42 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_exit_pos(t_pos *pos)
{
	if (pos)
		free(pos);
}

void	ft_exit_delta(t_delta *delta)
{
	if (delta)
		free(delta);
}

void	ft_exit_minimap(t_mini *minimap)
{
	if (minimap)
	{
		if (minimap->pos)
			ft_exit_pos(minimap->pos);
		if (minimap->delta)
			ft_exit_delta(minimap->delta);
		free(minimap);
	}
}

void	call_exit_map(t_map *map)
{
	int	i;

	i = 0;
	if (map)
	{
		// if (map->map_as_string)
		// {
		// 	free(map->map_as_string);
		// }
		if (map->map_as_arr)
		{
			while (map->map_as_arr[i])
			{
				free(map->map_as_arr[i]);
				i++;
			}
			free(map->map_as_arr);
		}
		free(map);
	}
}

void	call_exit(t_game *game)
{
	call_exit_map(game->map);
	ft_exit_minimap(game->minimap);
	if (game)
		free(game);
}
