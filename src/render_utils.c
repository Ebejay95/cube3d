/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 17:34:52 by ajehle            #+#    #+#             */
/*   Updated: 2024/10/04 11:53:43 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"


float	fish_eye_correction(t_game* game, float ray_len, float current_angle)
{
	return(ray_len + cos((current_angle - game->player->angle)));
}
