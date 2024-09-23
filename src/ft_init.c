/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 12:11:10 by ajehle            #+#    #+#             */
/*   Updated: 2024/09/23 16:13:20 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

mlx_t	*ft_init_window(t_game *game)
{
	game->mlx = mlx_init(1000, 1000,
			NAME_WINDOW, true);
	if (!game->mlx)
		return (NULL);
	return (game->mlx);
}

t_mini	*ft_initialize_minimap(void)
{
	t_mini	*mini;

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
	game->minimap = ft_initialize_minimap();
	if (!game->minimap)
		call_exit(game);
}
