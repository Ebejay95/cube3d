/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 12:11:10 by ajehle            #+#    #+#             */
/*   Updated: 2024/09/24 13:59:58 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_initialize_player(t_game *game)
{
	game->player = malloc(sizeof(t_player));
	if (!game->player)
		return ;
	game->player->x = game->map->spawn_x * CELL + (CELL / 2);
	game->player->y = game->map->spawn_y * CELL + (CELL / 2);
	game->player->angle = 0;
}

mlx_t	*ft_init_window(t_game *game)
{
	game->mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT,
			NAME_WINDOW, true);
	if (!game->mlx)
		return (NULL);
	return (game->mlx);
}

t_mini	*ft_initialize_minimap(t_game *game)
{
	t_mini	*mini;

	mini = NULL;
	mini = ft_calloc(sizeof(t_mini), 1);
	if (!mini)
		return (NULL);
	mini->player = NULL;
	mini->plyr_dir = NULL;
	mini->overlay = NULL;
	mini->pos_x = 1;
	mini->pos_y = 1;
	mini->delta_x = 0;
	mini->delta_y = 0;
	mini->angle = 0;
	mini->delta_x = cos(mini->angle) * 5;
	mini->delta_y = sin(mini->angle) * 5;
	mini->px_height = 100;
	mini->px_width = 200;
	mini->map_height = game->map->height;
	mini->map_width = game->map->width;
	return (mini);
}

void	ft_initialize_game(t_game	*game)
{
	game->map = NULL;
	game->minimap = NULL;
	game->mlx = NULL;
}

void	ft_initialize(t_game *game, int argc, char **argv)
{
	ft_initialize_game(game);
	get_map(game, argc, argv);
	if (!game->map)
		call_exit(game);
	print_map(game->map);
	game->minimap = ft_initialize_minimap(game);
	ft_initialize_player(game);
	if (!game->minimap)
		call_exit(game);
}
