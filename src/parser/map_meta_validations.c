/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_meta_validations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:02:27 by jeberle           #+#    #+#             */
/*   Updated: 2024/09/26 11:14:38 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	check_all_meta(t_game *game)
{
	if (!game->map->tex_west)
		return (0);
	if (!game->map->tex_east)
		return (0);
	if (!game->map->tex_north)
		return (0);
	if (!game->map->tex_south)
		return (0);
	if (!game->map->floor_set)
		return (0);
	if (!game->map->ceiling_set)
		return (0);
	return (1);
}

int	check_line_format(char *s1, size_t n)
{
	size_t	i;

	i = (n + 1);
	while (s1[i])
	{
		if (ft_isspace(s1[i]) && s1[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int	got_meta_line(t_game *game, char *s1, char *s2, size_t n)
{
	if (!ft_strncmp(s1, s2, n))
	{
		if (!check_line_format(s1, n))
			return (0);
		if (!ft_strcmp(s2, "NO ") && !game->map->tex_north)
			return (1);
		if (!ft_strcmp(s2, "SO ") && !game->map->tex_south)
			return (1);
		if (!ft_strcmp(s2, "WE ") && !game->map->tex_west)
			return (1);
		if (!ft_strcmp(s2, "EA ") && !game->map->tex_east)
			return (1);
		if (!ft_strcmp(s2, "F ") && !game->map->floor_set)
			return (1);
		if (!ft_strcmp(s2, "C ") && !game->map->ceiling_set)
			return (1);
		ft_fprintf(2, RED"a Meta define is not unique\n"D);
		return (0);
	}
	return (0);
}

void	retreive_meta(char *line, int *err, t_game *game)
{
	if (got_meta_line(game, line, "NO ", 3))
		set_textr_meta(err, line, game, 'n');
	else if (got_meta_line(game, line, "SO ", 3))
		set_textr_meta(err, line, game, 's');
	else if (got_meta_line(game, line, "WE ", 3))
		set_textr_meta(err, line, game, 'w');
	else if (got_meta_line(game, line, "EA ", 3))
		set_textr_meta(err, line, game, 'e');
	else if (got_meta_line(game, line, "F ", 2))
		set_color_meta(err, line, game, 'f');
	else if (got_meta_line(game, line, "C ", 2))
		set_color_meta(err, line, game, 'c');
	else
	{
		if (ft_strlen(line) == ft_strspn(line, MAP_CNT_CHARS))
		{
			ft_fprintf(2, RED"Received Meta Data in wrong format ");
			ft_fprintf(2, "or a mandatory Meta is missing because");
			ft_fprintf(2, " this seems to be map content: \n %s\n"D, line);
		}
		else
			ft_fprintf(2, RED"Received Meta Data in wrong format\n"D);
		(*err)++;
	}
}

void	get_map_meta(int fd, int *err, t_game *game)
{
	int		allfound;
	char	*line;

	allfound = 0;
	line = get_next_line(fd);
	while (line != NULL && !allfound && !(*err))
	{
		if (ft_strcmp(line, "\n"))
		{
			retreive_meta(line, err, game);
			allfound = check_all_meta(game);
		}
		free(line);
		line = NULL;
		if (!allfound)
			line = get_next_line(fd);
	}
	free(line);
	line = NULL;
}
