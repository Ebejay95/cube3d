/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_content_validations_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 00:07:09 by jeberle           #+#    #+#             */
/*   Updated: 2024/10/10 17:25:58 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/cub3d_bonus.h"

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
	check_doors(map, err);
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

void	clear_validation(t_map *m)
{
	int	y;
	int	x;
	int	dx;

	y = 0;
	while (y < m->height)
	{
		x = 0;
		while (x < m->width)
		{
			if (y == m->spawn_y && x == m->spawn_x)
				m->content[y][x] = m->spawn;
			if (m->content[y][x] == 'X')
				m->content[y][x] = '0';
			dx = 0;
			while (dx < m->door_count)
			{
				if (y == m->doors[dx]->y && x == m->doors[dx]->x)
				{
					if (m->doors[dx]->direction != '-')
						m->content[y][x] = ft_toupper(m->doors[dx]->direction);
				}
				dx++;
			}
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
	if (ft_strlen(content) != (size_t)ft_strspn(content, MAP_CNT_CHARS))
	{
		(*err)++;
		ft_fprintf(2, RED"Invalid char in map\n"D);
	}
	parse_map_array(game->map, map_split(content));
	map_validation(game->map, err);
	clear_validation(game->map);
	free(content);
	free(line);
	line = NULL;
}
