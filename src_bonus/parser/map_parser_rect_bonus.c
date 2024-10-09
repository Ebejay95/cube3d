/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_rect_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 00:05:02 by jeberle           #+#    #+#             */
/*   Updated: 2024/10/10 00:05:07 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/cub3d_bonus.h"

char	**allocate_result(size_t count)
{
	char	**result;

	result = (char **)malloc((count + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	result[count] = NULL;
	return (result);
}

char	**allocate_rect_array(int num_rows)
{
	char	**rect_array;

	rect_array = (char **)malloc((num_rows + 1) * sizeof(char *));
	if (rect_array == NULL)
		return (NULL);
	rect_array[num_rows] = NULL;
	return (rect_array);
}

char	**map_split(char *str)
{
	size_t	count;
	char	*trimmed_map;
	char	**result;

	trimmed_map = ft_strtrim(str, "\n");
	count = count_lines(trimmed_map);
	result = split_lines(trimmed_map, count);
	free(trimmed_map);
	return (result);
}
