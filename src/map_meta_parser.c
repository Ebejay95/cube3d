/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_meta_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:03:02 by jeberle           #+#    #+#             */
/*   Updated: 2024/09/25 12:49:07 by jeberle          ###   ########.fr       */
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

static char	*trim_whitespace_and_newline(char *str)
{
	char	*end;

	while (*str && (*str == ' ' || *str == '\t'))
		str++;
	end = str + ft_strlen(str) - 1;
	while (end > str && (*end == ' ' || *end == '\t' || *end == '\n'))
		end--;
	*(end + 1) = '\0';
	ft_printf("DEBUG: After trimming: '%s'\n", str);
	return (str);
}

uint32_t	create_color(int r, int g, int b)
{
	return (((r & 0xff) << 16) | ((g & 0xff) << 8) | (b & 0xff));
}

int	validate_color_component(char *component)
{
	int	i;
	int	value;

	i = 0;
	while (component[i])
	{
		if (!ft_isdigit(component[i]))
			return (0);
		i++;
	}
	value = ft_atoi(component);
	if (value < 0 || value > 255)
		return (0);
	return (1);
}

int	validate_color_split(char **split)
{
	if (!split || !split[0] || !split[1] || !split[2] || split[3])
	{
		ft_printf("DEBUG: Invalid number of color components\n");
		return (0);
	}
	if (!validate_color_component(split[0])
		|| !validate_color_component(split[1])
		|| !validate_color_component(split[2]))
	{
		ft_printf("DEBUG: Invalid color component(s)\n");
		return (0);
	}
	return (1);
}

uint32_t	parse_color(char *str, int start, int *err)
{
	char		**split;
	int			r;
	int			g;
	int			b;
	uint32_t	color;

	ft_printf("DEBUG: Parsing color string: '%s'\n", str);
	str = trim_whitespace_and_newline(str + start);
	split = ft_split(str, ',');
	if (!validate_color_split(split))
	{
		ft_array_free(split);
		*err = 1;
		return (0);
	}
	r = ft_atoi(split[0]);
	g = ft_atoi(split[1]);
	b = ft_atoi(split[2]);
	color = create_color(r, g, b);
	ft_array_free(split);
	ft_printf("DEBUG: Successfully parsed color\n");
	return (color);
}

void	set_color_meta(int *err, char *line, t_game *g, char kind)
{
	if (kind == 'f')
	{
		g->map->floor = parse_color(line, 1, err);
		if (!(*err))
			g->map->floor_set = 1;
	}
	if (kind == 'c')
	{
		g->map->ceiling = parse_color(line, 1, err);
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
