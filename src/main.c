/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 11:12:25 by ajehle            #+#    #+#             */
/*   Updated: 2024/09/14 11:16:33 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/cub3d.h"

void	check_leaks(void)
{
	system("leaks cub3d");
}

void	print_2d_arr(char **map_in_arr)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	ft_printf("	[0][1][2][3][4][5][6][7][8][9][10]\n");
	while (map_in_arr[i])
	{
		ft_printf("[%i]	", i);
		while (map_in_arr[i][j])
		{
			ft_printf(" %c ", map_in_arr[i][j]);
			j++;
		}
		ft_printf("\n");
		j = 0;
		i++;
	}
}


t_game	*ft_initialize_game(t_map *map)
{
	t_game	*game;

	game = NULL;
	game = ft_calloc(sizeof(t_game), 1);
	if (!game)
		return (NULL);
	game->map = map;
	game->game_window = NULL;
	game->game_image = NULL;
	game->frame = 0;
	return (game);
}

t_map	*ft_initialize_map(char* string)
{
	t_map*	map;

	map = NULL;
	map = ft_calloc(sizeof(t_map), 1);
	if (!map)
		return (NULL);
	map->map_as_string = string;
	map->map_as_arr = ft_split(map->map_as_string, '\n');
	map->width = 1000;
	map->height = 650;
	print_2d_arr(map->map_as_arr);

	return (map);
}

mlx_t	*ft_init_window(t_game *game)
{
	// game->map->width = ft_strlen(game->map->map_as_arr[0]) * PIXEL;
	// game->map->height = get_height(game->map->map_as_arr) * PIXEL;
	game->game_window = mlx_init(game->map->width, game->map->height,
			NAME_WINDOW, true);
	if (!game->game_window)
		return (NULL);
	return (game->game_window);
}
t_game	*ft_initialize(t_map *map)
{
	t_game	*game;

	game = ft_initialize_game(map);
	if (!game)
		return (NULL);
	if (!ft_init_window(game))
		return (NULL);
		// return (ft_printf("Error\n"), call_exit(game), NULL);
	return (game);
}


void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(game->game_window);

	return ;
}

void	start_game(t_game *game)
{
	if (game)
	{
		mlx_set_setting(MLX_STRETCH_IMAGE, 1);
		mlx_key_hook(game->game_window, &my_keyhook, game);
		mlx_loop(game->game_window);
		mlx_terminate(game->game_window);
	}
}

int	load_textures(t_game *game)
{
	int	i;

	i = 0;
	// i += ft_load_textures_minimap(game);

	// if (i)
	// 	return (call_exit(game), 1);
	return (i);
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
	if (game)
		free(game);
}

int	main(int argc, char **argv)
{
	atexit(check_leaks);
	t_map	*map;
	t_game	*game;
	t_delta *player;

	map = NULL;
	game = NULL;

	map = ft_initialize_map("1111111111\n1P00000001\n1000001001\n1000000001\n1000000001\n1000000001\n1111100001\n1000000001\n1000000001\n1111111111");
	game = ft_initialize(map);

	start_game(game);
	call_exit(game);
	return (0);
}



