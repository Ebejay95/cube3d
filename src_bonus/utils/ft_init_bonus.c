/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 23:57:46 by jeberle           #+#    #+#             */
/*   Updated: 2024/10/14 21:46:01 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/cub3d_bonus.h"

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
	game->run_music = true;
}

void	ft_initialize(t_game *game, int argc, char **argv)
{
	//game->hand_images[0] = game->map->hand_one;
	//game->hand_images[1] = game->map->hand_two;
	//game->hand_images[2] = game->map->hand_three;
	//game->hand_images[3] = game->map->hand_four;
	//game->hand_images[4] = game->map->hand_five;
	//game->hand_images[5] = game->map->hand_six;
	ft_initialize_game(game);
	get_map(game, argc, argv);
	if (!game->map)
	{
		call_exit(game);
		return ;
	}
	print_map(game->map);
	ft_initialize_player(game);
	if (!ft_init_window(game))
	{
		call_exit(game);
		return ;
	}
}
