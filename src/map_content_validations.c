/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_content_validations.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:07:50 by jeberle           #+#    #+#             */
/*   Updated: 2024/09/23 08:50:42 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	get_map_content(int fd, int *err, t_game *game)
{
	char	*line;
	char	*content;
	char	*temp;

	content = ft_strdup("");
	line = get_next_line(fd);
	while (line != NULL && !(*err))
	{
		if (ft_strlen(line) != ft_strspn(line, MAP_CNT_CHARS))
		{
			(*err)++;
			ft_fprintf(2, RED"Invalid char in map:\n%s"D, line);
		}
		temp = ft_strjoin(content, line);
		free(content);
		content = temp;
		free(line);
		line = get_next_line(fd);
	}
	game->map->content = parse_map_array(map_split(content));
	free(content);
}
