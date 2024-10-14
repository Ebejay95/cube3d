/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_content_validation_bonus3.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 21:42:52 by jeberle           #+#    #+#             */
/*   Updated: 2024/10/14 21:44:22 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/cub3d_bonus.h"

void	handle_clear_door(t_map *m, int x, int y, int dx)
{
	if (y == m->doors[dx]->y && x == m->doors[dx]->x)
	{
		if (m->doors[dx]->direction != '-')
			m->content[y][x] = ft_toupper(m->doors[dx]->direction);
	}
}
