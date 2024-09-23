/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 12:11:10 by ajehle            #+#    #+#             */
/*   Updated: 2024/09/23 09:07:52 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_printmetas(t_map *map)
{
	ft_printf("\nTexture Pointers:\n");
	ft_printf("West: %p\n", (void *)map->tex_west);
	ft_printf("East: %p\n", (void *)map->tex_east);
	ft_printf("North: %p\n", (void *)map->tex_north);
	ft_printf("South: %p\n", (void *)map->tex_south);
	ft_printf("\nImage Pointers:\n");
	ft_printf("West: %p\n", (void *)map->img_west);
	ft_printf("East: %p\n", (void *)map->img_east);
	ft_printf("North: %p\n", (void *)map->img_north);
	ft_printf("South: %p\n", (void *)map->img_south);
	ft_printf("\nColors:\n");
	ft_printf("Ceiling: 0x%08X\n", map->ceiling);
	ft_printf("Floor: 0x%08X\n", map->floor);
	ft_printf("\nFlags:\n");
	ft_printf("Ceiling set: %d\n", map->ceiling_set);
	ft_printf("Floor set: %d\n", map->floor_set);
}

void	print_map_debug(t_map *map)
{
	int	i;
	int	j;

	if (!map)
	{
		ft_printf("Map is NULL or empty\n");
		return ;
	}
	if (map->content)
	{
		while (map->content[i])
		{
			j = 0;
			while (map->content[i][j])
			{
				ft_printf(Y"|"D);
				ft_printf(B"%c"D, map->content[i][j]);
				j++;
			}
			ft_printf(Y"|"D);
			ft_printf("\n");
			i++;
		}
	}
	ft_printmetas(map);
}

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

t_game	*ft_initialize_game(void)
{
	t_game	*game;

	game = NULL;
	game = ft_calloc(sizeof(t_game), 1);
	if (!game)
		return (NULL);
	game->map = NULL;
	game->minimap = NULL;
	game->mlx = NULL;
	return (game);
}

t_game	*ft_initialize(int argc, char **argv)
{
	t_game	*game;

	game = ft_initialize_game();
	if (!game)
		return (call_exit(game), NULL);
	get_map(game, argc, argv);
	if (!game->map)
		return (call_exit(game), NULL);
	print_map_debug(game->map);
	game->minimap = ft_initialize_minimap();
	if (!game->minimap)
		return (call_exit(game), NULL);
	return (game);
}
