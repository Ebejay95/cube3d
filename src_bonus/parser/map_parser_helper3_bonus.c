/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_helper3_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 00:05:17 by jeberle           #+#    #+#             */
/*   Updated: 2024/10/10 00:05:18 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/cub3d_bonus.h"

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
