/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 12:11:27 by ajehle            #+#    #+#             */
/*   Updated: 2024/09/19 14:41:28 by jeberle          ###   ########.fr       */
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

void	call_exit_map(t_map *map)
{
	int	i;

	i = 0;
	if (map)
	{
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
	if (game)
	{
		call_exit_map(game->map);
		call_exit_minimap(game->minimap);
		free(game);
	}
}
