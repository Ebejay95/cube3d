/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 09:08:29 by ajehle            #+#    #+#             */
/*   Updated: 2024/09/23 16:59:02 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	load_textures(t_game *game)
{
	int	i;

	i = 0;
	calc_delta(game, ' ');
	i += ft_load_textures_minimap(game);
	i += draw_direction(game);
	if (i)
		return (call_exit(game), 1);
	return (i);
}
