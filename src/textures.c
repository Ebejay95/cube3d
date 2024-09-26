/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 09:08:29 by ajehle            #+#    #+#             */
/*   Updated: 2024/09/26 11:08:20 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	load_textures(t_game *game)
{
	int	i;

	i = 0;
	calc_delta(game, ' ');
	// i += ft_load_textures_minimap(game);
	if (i)
		return (call_exit(game), 1);
	return (i);
}
