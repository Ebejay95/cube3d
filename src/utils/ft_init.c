/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 12:11:10 by ajehle            #+#    #+#             */
/*   Updated: 2024/10/07 15:00:26 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_initialize_player(t_game *game)
{
	game->player = malloc(sizeof(t_player));
	if (!game->player)
		return ;
	game->player->x = game->map->spawn_x * CELL + (CELL / 2);
	game->player->y = game->map->spawn_y * CELL + (CELL / 2);
	if (game->map->spawn == 'E')
		game->player->angle = 0;
	else if (game->map->spawn == 'S')
		game->player->angle = M_PI / 2;
	else if (game->map->spawn == 'W')
		game->player->angle = M_PI;
	else if (game->map->spawn == 'N')
		game->player->angle = 3 * M_PI / 2;
}

mlx_t	*ft_init_window(t_game *game)
{
	game->mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT,
			NAME_WINDOW, true);
	if (!game->mlx)
		return (NULL);
	return (game->mlx);
}

void	ft_initialize_game(t_game	*game)
{
	game->map = NULL;
	game->mlx = NULL;
	game->surface = NULL;
	game->key_states.w_pressed = false;
	game->key_states.s_pressed = false;
	game->key_states.a_pressed = false;
	game->key_states.d_pressed = false;
	game->key_states.left_pressed = false;
	game->key_states.right_pressed = false;
}

void	ft_initialize(t_game *game, int argc, char **argv)
{
	ft_initialize_game(game);
	get_map(game, argc, argv);
	if (!game->map)
	{
		call_exit(game);
		return ;
	}
	print_map(game->map);
	ft_initialize_player(game);

}
