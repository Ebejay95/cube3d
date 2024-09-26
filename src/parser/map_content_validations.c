/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_content_validations.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:07:50 by jeberle           #+#    #+#             */
/*   Updated: 2024/09/26 11:14:32 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	check_chars(t_map *map, int *err)
{
	int	y;

	y = 0;
	while (y < map->height && !(*err))
	{
		if (map->width != (int)ft_strspn(map->content[y], MAP_CNT_CHARS))
		{
			(*err)++;
			ft_fprintf(2, RED"Invalid char in map:\n"D);
			print_map_error(map, y, ft_strspn(map->content[y], MAP_CNT_CHARS));
		}
		y++;
	}
}

int	has_defined_insides(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->content[y][x] == '0')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

void	map_validation(t_map *map, int *err)
{
	int	y;
	int	x;

	check_chars(map, err);
	check_spawn(map, err);
	while (has_defined_insides(map) && !(*err))
	{
		init_flood(map);
		flood(map);
	}
	y = 0;
	while (y < map->height && !(*err))
	{
		x = 0;
		while (x < map->width && !(*err))
		{
			if (map->content[y][x] == 'X')
				check_the_spot(map, y, x, err);
			x++;
		}
		y++;
	}
}

void	clear_validation(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (y == map->spawn_y && x == map->spawn_x)
				map->content[y][x] = map->spawn;
			if (map->content[y][x] == 'X')
				map->content[y][x] = '0';
			x++;
		}
		y++;
	}
}

void	get_map_content(int fd, int *err, t_game *game)
{
	char	*line;
	char	*content;
	char	*temp;

	content = ft_strdup("");
	line = get_next_line(fd);
	while (line != NULL && !(*err))
	{
		temp = ft_strjoin(content, line);
		free(content);
		content = temp;
		free(line);
		line = get_next_line(fd);
	}
	parse_map_array(game->map, map_split(content));
	map_validation(game->map, err);
	clear_validation(game->map);
	free(content);
	free(line);
	line = NULL;
}
