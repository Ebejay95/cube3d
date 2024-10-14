/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_content_validations_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 00:07:09 by jeberle           #+#    #+#             */
/*   Updated: 2024/10/14 21:56:13 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/cub3d_bonus.h"

void	process_clear_doors(t_map *m, int x, int y)
{
	int	dx;

	dx = 0;
	while (dx < m->door_count)
	{
		handle_clear_door(m, x, y, dx);
		dx++;
	}
}

void	process_clear_cell(t_map *m, int x, int y)
{
	handle_clear_spawn_point(m, x, y);
	handle_clear_x_content(m, x, y);
	process_clear_doors(m, x, y);
}

void	process_clear_row(t_map *m, int y)
{
	int	x;

	x = 0;
	while (x < m->width)
	{
		process_clear_cell(m, x, y);
		x++;
	}
}

void	clear_validation(t_map *m)
{
	int	y;

	y = 0;
	while (y < m->height)
	{
		process_clear_row(m, y);
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
