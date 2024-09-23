/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_meta_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:03:02 by jeberle           #+#    #+#             */
/*   Updated: 2024/09/23 16:49:45 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	*get_textr_path(char *line, size_t size, int *err)
{
	size_t	i;
	size_t	j;
	size_t	new_size;
	char	*path;

	i = 0;
	while (line[i] && i < size)
		i++;
	if (i < size)
		(*err)++;
	new_size = i;
	while (line[new_size] && line[new_size] != '\n' && line[new_size] != ' ')
		new_size++;
	new_size = new_size - i;
	path = malloc(sizeof(char) * (new_size + 1));
	if (!path)
		return ((*err)++, NULL);
	j = 0;
	while (j < new_size)
	{
		path[j] = line[j + i];
		j++;
	}
	path[new_size] = '\0';
	return (path);
}

uint32_t	parse_color(char *str, int start, int *err)
{
	char		**split;
	int			r;
	int			g;
	int			b;
	uint32_t	color;

	split = ft_split(str + start, ',');
	if (!split || !split[0] || !split[1] || !split[2] || split[3])
	{
		ft_array_free(split);
		*err = 1;
		return (0);
	}
	r = ft_atoi(split[0]);
	g = ft_atoi(split[1]);
	b = ft_atoi(split[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
	{
		*err = 1;
		return (0);
	}
	color = (r << 24) | (g << 16) | (b << 8) | 0xFF;
	ft_array_free(split);
	return (color);
}

void	set_color_meta(int *err, char *line, t_game *g, char kind)
{
	if (kind == 'f')
	{
		g->map->floor = parse_color(line, 2, err);
		if (!(*err))
			g->map->floor_set = 1;
	}
	if (kind == 'c')
	{
		g->map->ceiling = parse_color(line, 2, err);
		if (!(*err))
			g->map->ceiling_set = 1;
	}
	if (*err)
	{
		ft_fprintf(2, RED"Error loading color in map meta definition: ");
		ft_fprintf(2, "%s\n"D, line);
	}
}

void	set_textr_meta(int *err, char *line, t_game *g, char ornttn)
{
	char	*path;
	int		fd;

	path = get_textr_path(line, 3, err);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		(*err)++;
	else
		close(fd);
	if (ornttn == 'w')
		g->map->tex_west = mlx_load_png(path);
	if (ornttn == 'n')
		g->map->tex_north = mlx_load_png(path);
	if (ornttn == 'e')
		g->map->tex_east = mlx_load_png(path);
	if (ornttn == 's')
		g->map->tex_south = mlx_load_png(path);
	if (*err)
	{
		ft_fprintf(2, RED"Error loading texture in map meta definition: "D);
		ft_fprintf(2, "%s\n", path);
	}
	free(path);
}
