/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 08:50:56 by jeberle           #+#    #+#             */
/*   Updated: 2024/09/23 09:01:18 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

size_t	count_lines(const char *str)
{
	size_t	count;
	size_t	i;

	count = 1;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			count++;
		i++;
	}
	return (count);
}

char	**split_lines(const char *str, size_t count)
{
	char		**result;
	const char	*start;
	size_t		i;
	size_t		j;
	size_t		len;

	result = allocate_result(count);
	if (!result)
		return (NULL);
	start = str;
	j = 0;
	i = 0;
	while (i <= ft_strlen(str))
	{
		if (str[i] == '\n' || str[i] == '\0')
		{
			len = &str[i] - start;
			if (!alloc_and_cpy_line(result, j, start, len))
				return (NULL);
			start = &str[i + 1];
			j++;
		}
		i++;
	}
	return (result);
}

void	get_map_dimensions(char **splits, int *max_len, int *num_rows)
{
	int	i;
	int	len;

	i = 0;
	*max_len = 0;
	*num_rows = 0;
	while (splits[i] != NULL)
	{
		len = ft_strlen(splits[i]);
		if (len > *max_len)
			*max_len = len;
		(*num_rows)++;
		i++;
	}
}

void	free_splits(char **splits)
{
	int	i;

	i = 0;
	while (splits[i] != NULL)
	{
		free(splits[i]);
		i++;
	}
	free(splits);
}

char	**parse_map_array(char **splits)
{
	int		max_len;
	int		num_rows;
	char	**rect_array;

	get_map_dimensions(splits, &max_len, &num_rows);
	rect_array = allocate_rect_array(num_rows);
	if (rect_array == NULL)
		return (NULL);
	if (!fill_rect_array(rect_array, splits, max_len, num_rows))
	{
		free_splits(splits);
		return (NULL);
	}
	free_splits(splits);
	return (rect_array);
}
