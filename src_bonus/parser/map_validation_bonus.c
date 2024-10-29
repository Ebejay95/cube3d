/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 00:03:01 by jeberle           #+#    #+#             */
/*   Updated: 2024/10/29 10:36:08 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/cub3d_bonus.h"

int	validate_map(t_game *game, char *filename)
{
	int		fd;
	int		problem;

	problem = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (1);
	get_map_meta(fd, &problem, game);
	get_map_content(fd, &problem, game);
	close(fd);
	if (problem)
	{
		call_exit(game);
		return (1);
	}
	return (0);
}

int	validate_input(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr_fd(2, RED"./cube3d [map.cub]\n"D);
		return (1);
	}
	if (!ft_strendswith(argv[1], ".cub"))
	{
		ft_putstr_fd(2, RED"map must be .cub file\n"D);
		return (1);
	}
	if (access(argv[1], R_OK) != 0)
	{
		ft_putstr_fd(2, RED"cannot read from map file\n"D);
		return (1);
	}
	return (0);
}

void	setup_game_stuff(t_game *game)
{
	game->map->content = NULL;
	game->map->tex_west = NULL;
	game->map->tex_east = NULL;
	game->map->tex_north = NULL;
	game->map->tex_south = NULL;
	game->map->tex_door = NULL;
	game->map->ceiling = 0;
	game->map->floor = 0;
	game->map->ceiling_set = 0;
	game->map->floor_set = 0;
	game->map->width = 0;
	game->map->height = 0;
	game->map->spawn_x = -1;
	game->map->spawn_y = -1;
	game->map->spawn = '-';
	game->map->door_count = 0;
}

void	get_map(t_game *game, int argc, char **argv)
{
	game->map = malloc(sizeof(t_map));
	if (!game->map)
		return ;
	setup_game_stuff(game);
	if (validate_input(argc, argv) > 0)
	{
		call_exit(game);
		return ;
	}
	game->map->hand_one = mlx_load_png("assets/hand_1.png");
	game->map->hand_two = mlx_load_png("assets/hand_2.png");
	game->map->hand_three = mlx_load_png("assets/hand_3.png");
	game->map->hand_four = mlx_load_png("assets/hand_4.png");
	game->map->hand_five = mlx_load_png("assets/hand_5.png");
	game->map->hand_six = mlx_load_png("assets/hand_6.png");
	if (validate_map(game, argv[1]) > 0)
		call_exit(game);
}
