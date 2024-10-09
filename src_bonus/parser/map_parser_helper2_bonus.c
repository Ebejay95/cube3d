/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_helper2_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 00:05:28 by jeberle           #+#    #+#             */
/*   Updated: 2024/10/10 00:05:34 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/cub3d_bonus.h"

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
