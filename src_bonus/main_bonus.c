/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 23:56:58 by jeberle           #+#    #+#             */
/*   Updated: 2024/10/29 11:13:00 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/cub3d_bonus.h"

void	check_leaks(void)
{
	system("leaks cub3D");
}

int	main(int argc, char **argv)
{
	t_game	game;

	atexit(check_leaks);
	ft_initialize(&game, argc, argv);
	if (!game.map)
	{
		call_exit(&game);
		return (1);
	}
	if (!ft_init_window(&game))
		return (ft_printf(RED"Error init window\n"D), call_exit(&game), 0);
	game.hand_images[0] = mlx_texture_to_image(game.mlx, game.map->hand_one);
	game.hand_images[1] = mlx_texture_to_image(game.mlx, game.map->hand_two);
	game.hand_images[2] = mlx_texture_to_image(game.mlx, game.map->hand_three);
	game.hand_images[3] = mlx_texture_to_image(game.mlx, game.map->hand_four);
	game.hand_images[4] = mlx_texture_to_image(game.mlx, game.map->hand_five);
	game.hand_images[5] = mlx_texture_to_image(game.mlx, game.map->hand_six);
	start_game(&game);
	call_exit(&game);
	return (0);
}
