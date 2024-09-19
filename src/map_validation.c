/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:10:24 by jeberle           #+#    #+#             */
/*   Updated: 2024/09/19 16:20:01 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_all_meta(t_map *map)
{
	if (!map->tex_west && !map->img_west)
		return (0);
	if (!map->tex_east && !map->img_east)
		return (0);
	if (!map->tex_north && !map->img_north)
		return (0);
	if (!map->tex_south && !map->img_south)
		return (0);
	if (!map->ceiling_set && !map->floor_set)
		return (0);
	return (1);
}

void	retreive_meta(char *line, int *err, t_map *map)
{
	if (ft_strncmp(line, "NO ", 3))
		set_textr_meta(err, line, map, 'n');
	else if (ft_strncmp(line, "SO ", 3))
		set_textr_meta(err, line, map, 's');
	else if (ft_strncmp(line, "WE ", 3))
		set_textr_meta(err, line, map, 'w');
	else if (ft_strncmp(line, "EA ", 3))
		set_textr_meta(err, line, map, 'e');
	else if (ft_strncmp(line, "F ", 2))
		set_color_meta(err, line, map, 'f');
	else if (ft_strncmp(line, "C ", 2))
		set_color_meta(err, line, map, 'c');
	else
		(*err)++;
}

void	get_map_meta(int fd, int *err, t_map *map)
{
	int	allfound;

	allfound = 0;
	line = get_next_line(fd);
	while (line != NULL && !allfound && !err)
	{
		if (!ft_strcmp(line, "\n"))
		{
			retreive_meta(line, err, map);
			allfound = check_all_meta(map);
		}
		free(line);
		line = get_next_line(fd);
	}
}

int	validate_map(t_map *map, char *filename)
{
	int		fd;
	char	*mapstring;
	int		problem;

	problem = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (ft_putstr_fd(2, RED"file cannot be read from\n"D), NULL);
	get_map_meta(fd, &problem, map);
	get_map_content(fd, &problem, map);
	close(fd)
	if (problem)
		call_exit_map(map);
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

t_map	*get_map(int argc, char **argv)
{
	t_map *map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->map_as_arr = NULL;
	map->tex_west = NULL;
	map->img_west = NULL;
	map->tex_east = NULL;
	map->img_east = NULL;
	map->tex_north = NULL;
	map->img_north = NULL;
	map->tex_south = NULL;
	map->img_south = NULL;
	map->ceiling = 0;
	map->floor = 0;
	map->ceiling_set = 0;
	map->floor_set = 0;
	if (validate_input(argc, argv) > 0)
		return (free(map), NULL);
	if (validate_map(map, argv[1]) > 0)
		return (free(map), NULL);
	return (map);
}
