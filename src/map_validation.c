/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:10:24 by jeberle           #+#    #+#             */
/*   Updated: 2024/09/19 14:52:22 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"


char	*get_file_content(char *filename)
{
	char	*cnt;
	char	*tmp;
	char	*line;
	int		fd;

	cnt = ft_strdup("");
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (ft_putstr_fd(2, RED"file cannot be read from\n"D), cnt);
	line = get_next_line(fd);
	while (line != NULL)
	{
		tmp = ft_strjoin(cnt, line);
		if (tmp == NULL)
		{
			free(line);
			return (close(fd), cnt);
		}
		free(cnt);
		cnt = tmp;
		free(line);
		line = get_next_line(fd);
	}
	return (close(fd), cnt);
}

int	validate_map(char **map_array, char *map)
{
	char	*mapstring;

	mapstring = get_file_content(map);
	ft_printf(Y"%s"D, mapstring);
	//game->map = ft_strtrim(mapstring, "\n");
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

char **get_mapstr(int argc, char **argv)
{
	char	**map_array;

	map_array = NULL;
	if (validate_input(argc, argv) > 0)
		return (NULL);
	if (validate_map(map_array, argv[1]) > 0)
		return (NULL);
	return (map_array);
}
