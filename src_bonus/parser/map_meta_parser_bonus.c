/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_meta_parser_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 00:06:42 by jeberle           #+#    #+#             */
/*   Updated: 2024/10/10 00:06:48 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/cub3d_bonus.h"

char	**split_and_trim(char *str, char s)
{
	char	**split;
	char	*tmp_trm;
	int		i;

	i = 0;
	split = ft_split(str, s);
	while (split && split[i])
	{
		tmp_trm = ft_strtrim(split[i], " ");
		free(split[i]);
		split[i] = tmp_trm;
		i++;
	}
	return (split);
}

uint32_t	parse_color(char *str, int start, int *err)
{
	char		**split;
	int			r;
	int			g;
	int			b;
	uint32_t	color;

	str = trim_whitespace_and_newline(str + start);
	split = split_and_trim(str, ',');
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
	return (color);
}

void	set_color_meta(int *err, char *line, t_game *g, char kind)
{
	uint32_t	color;

	color = parse_color(line, 1, err);
	if (!(*err))
	{
		if (kind == 'f')
		{
			g->map->floor = color;
			g->map->floor_set = 1;
		}
		else if (kind == 'c')
		{
			g->map->ceiling = color;
			g->map->ceiling_set = 1;
		}
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
	char	*tmp_path;

	tmp_path = get_textr_path(line, 3, err);
	path = ft_strtrim(tmp_path, " ");
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
	ft_multifree(NULL, NULL, path, tmp_path);
}
