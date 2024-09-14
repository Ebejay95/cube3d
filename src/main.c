/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 11:12:25 by ajehle            #+#    #+#             */
/*   Updated: 2024/09/14 12:17:56 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/cub3d.h"

void	check_leaks(void)
{
	system("leaks cub3d");
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(game->game_mlx);
	if (mlx_is_key_down(game->game_mlx, MLX_KEY_W))
	{
		game->minimap->image->instances[0].y -= 5;
	}
	if (mlx_is_key_down(game->game_mlx, MLX_KEY_S))
	{
		game->minimap->image->instances[0].y += 5;
	}
	if (mlx_is_key_down(game->game_mlx, MLX_KEY_A))
	{
		game->minimap->image->instances[0].x -= 5;
	}
	if (mlx_is_key_down(game->game_mlx, MLX_KEY_D))
	{
		game->minimap->image->instances[0].x += 5;
	}
	if (mlx_is_key_down(game->game_mlx, MLX_KEY_RIGHT))
	{
		// game->minimap->delta->a += 0.1;
		// if(game->minimap->delta->a >  2 * PI)
		// 	game->minimap->delta->a -= 2 * PI;
		// game->minimap->delta->x = cos(game->minimap->delta->a) * 5;
		// game->minimap->delta->y = sin(game->minimap->delta->a) * 5;

	}
	if (mlx_is_key_down(game->game_mlx, MLX_KEY_LEFT))
	{
		// game->minimap->delta->a -= 0.1;
		// if(game->minimap->delta->a < 0)
		// 	game->minimap->delta->a += 2 * PI;
		// game->minimap->delta->x = cos(game->minimap->delta->a) * 5;
		// game->minimap->delta->y = sin(game->minimap->delta->a) * 5;
	}
	// draw_direction(game);
	// printf("X:%i	Y:%i	DX:%f	DY:%f	A:%f\n",game->minimap->image->instances[0].x,game->minimap->image->instances[0].y, game->minimap->delta->x, game->minimap->delta->y, game->minimap->delta->a);

	return ;
}


void	start_game(t_game *game)
{
	if (game)
	{
		mlx_set_setting(MLX_STRETCH_IMAGE, 1);
		mlx_key_hook(game->game_mlx, &my_keyhook, game);
		mlx_loop(game->game_mlx);
		mlx_terminate(game->game_mlx);
	}
}

int	main(int argc, char **argv)
{
	atexit(check_leaks);
	t_map*	map;
	t_game*	game;
	t_mini*	mini;

	map = NULL;
	game = NULL;
	mini = NULL;

	map = ft_initialize_map("1111111111\n1P00000001\n1000001001\n1000000001\n1000000001\n1000000001\n1111100001\n1000000001\n1000000001\n1111111111");
	mini = ft_initialize_minimap(map);
	game = ft_init(map, mini);

	start_game(game);
	call_exit(game);
	return (0);
}



