/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_rect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 08:51:37 by jeberle           #+#    #+#             */
/*   Updated: 2024/09/26 11:14:41 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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
