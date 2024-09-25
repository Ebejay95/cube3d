/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 08:50:56 by jeberle           #+#    #+#             */
/*   Updated: 2024/09/25 14:23:58 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

size_t	count_lines(char *str)
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

int	alloc_and_cpy_line(char **result, t_split_context *ctx, size_t len)
{
	result[ctx->j] = ft_calloc(len + 1, sizeof(char));
	if (!result[ctx->j])
	{
		free_splits(result);
		return (0);
	}
	ft_strlcpy(result[ctx->j], ctx->start, len + 1);
	return (1);
}

char	**split_lines_init(size_t count)
{
	char	**result;

	result = allocate_result(count);
	if (!result)
		return (NULL);
	return (result);
}

char	**split_lines_process(char **result, t_split_context *ctx)
{
	size_t	len;

	if (ctx->str[ctx->i] == '\n' || ctx->str[ctx->i] == '\0')
	{
		len = &ctx->str[ctx->i] - ctx->start;
		if (!alloc_and_cpy_line(result, ctx, len))
			return (NULL);
		ctx->start = &ctx->str[ctx->i + 1];
		ctx->j++;
	}
	ctx->i++;
	return (result);
}

char	**split_lines(char *str, size_t count)
{
	char			**result;
	t_split_context	ctx;

	result = split_lines_init(count);
	if (!result)
		return (NULL);
	ctx.str = str;
	ctx.count = count;
	ctx.i = 0;
	ctx.j = 0;
	ctx.start = str;
	while (ctx.i <= ft_strlen(str))
	{
		result = split_lines_process(result, &ctx);
		if (!result)
			return (NULL);
	}
	return (result);
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

void	update_map_bounds(char c, t_map_bounds *bounds, int j)
{
	if (c != ' ' && c != '\t')
	{
		if (j < bounds->left)
			bounds->left = j;
		if (j > bounds->right)
			bounds->right = j;
	}
}

void	find_map_width_init(t_map_bounds *bounds)
{
	bounds->left = INT_MAX;
	bounds->right = 0;
}

void	find_map_width_process(char **splits, int i, t_map_bounds *bounds)
{
	int	j;

	j = 0;
	while (splits[i][j])
	{
		update_map_bounds(splits[i][j], bounds, j);
		j++;
	}
}

void	find_map_width(char **splits, t_map_bounds *bounds)
{
	int	i;

	find_map_width_init(bounds);
	i = bounds->start;
	while (i <= bounds->end)
	{
		find_map_width_process(splits, i, bounds);
		i++;
	}
}

char	*create_new_line(char *old_line, t_map_bounds *bounds)
{
	char	*new_line;
	int		j;
	int		new_width;

	new_width = bounds->right - bounds->left + 1;
	new_line = ft_calloc(new_width + 1, sizeof(char));
	if (!new_line)
		return (NULL);
	j = 0;
	while (j < new_width)
	{
		if (bounds->left + j < (int)ft_strlen(old_line))
			new_line[j] = old_line[bounds->left + j];
		else
			new_line[j] = ' ';
		j++;
	}
	new_line[new_width] = '\0';
	return (new_line);
}

void	trim_map_content(char **splits, t_map_bounds *bounds)
{
	int		i;
	char	*new_line;

	i = bounds->start;
	while (i <= bounds->end)
	{
		new_line = create_new_line(splits[i], bounds);
		if (!new_line)
			return ;
		free(splits[i]);
		splits[i] = new_line;
		i++;
	}
}

int	allocate_map_content(t_map *map)
{
	map->content = ft_calloc(map->height + 1, sizeof(char *));
	if (!map->content)
		return (0);
	return (1);
}

int	copy_map_content_process(t_map *map, char **splits, int start, int i)
{
	map->content[i] = ft_strdup(splits[start + i]);
	if (!map->content[i])
	{
		while (i > 0)
			free(map->content[--i]);
		free(map->content);
		map->content = NULL;
		return (0);
	}
	return (1);
}

int	copy_map_content(t_map *map, char **splits, int start)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		if (!copy_map_content_process(map, splits, start, i))
			return (0);
		i++;
	}
	map->content[map->height] = NULL;
	return (1);
}

void	parse_map_array(t_map *map, char **splits)
{
	t_map_bounds	bounds;

	find_map_bounds(splits, &bounds.start, &bounds.end);
	if (bounds.start == -1 || bounds.end == -1)
	{
		free_splits(splits);
		return ;
	}
	find_map_width(splits, &bounds);
	trim_map_content(splits, &bounds);
	map->height = bounds.end - bounds.start + 1;
	map->width = bounds.right - bounds.left + 1;
	if (!allocate_map_content(map))
	{
		free_splits(splits);
		return ;
	}
	if (!copy_map_content(map, splits, bounds.start))
	{
		free_splits(splits);
		return ;
	}
	free_splits(splits);
}
