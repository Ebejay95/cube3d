/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_rect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 08:51:37 by jeberle           #+#    #+#             */
/*   Updated: 2024/09/23 14:25:47 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	**allocate_result(size_t count)
{
	char	**result;

	result = (char **)malloc((count + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	result[count] = NULL;
	return (result);
}

int	alloc_and_cpy_line(char **result, size_t j, const char *start, size_t len)
{
	result[j] = (char *)malloc((len + 1) * sizeof(char));
	if (!result[j])
	{
		while (j > 0)
			free(result[--j]);
		free(result);
		return (0);
	}
	ft_strncpy(result[j], start, len);
	result[j][len] = '\0';
	return (1);
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

int	fill_rect_array(char **rect_array, char **splits, int max_len, int num_rows)
{
	int	i;
	int	j;
	int	orig_len;

	i = 0;
	while (i < num_rows)
	{
		rect_array[i] = (char *)malloc((max_len + 1) * sizeof(char));
		if (rect_array[i] == NULL)
		{
			while (i > 0)
				free(rect_array[--i]);
			free(rect_array);
			return (0);
		}
		ft_strcpy(rect_array[i], splits[i]);
		orig_len = ft_strlen(splits[i]);
		j = orig_len;
		while (j < max_len)
			rect_array[i][j++] = ' ';
		rect_array[i][max_len] = '\0';
		i++;
	}
	return (1);
}
