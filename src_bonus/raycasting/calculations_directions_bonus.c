/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations_directions_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 00:02:39 by jeberle           #+#    #+#             */
/*   Updated: 2024/10/10 00:02:45 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/cub3d_bonus.h"

int	is_looking_right(float angle)
{
	if (angle >= 0 && angle < M_PI_2)
		return (1);
	return (0);
}

int	is_looking_down(float angle)
{
	if (angle >= M_PI_2 && angle < M_PI)
		return (1);
	return (0);
}

int	is_looking_left(float angle)
{
	if (angle >= M_PI && angle < 3 * M_PI_2)
		return (1);
	return (0);
}

int	is_looking_up(float angle)
{
	if (angle >= 3 * M_PI_2 && angle < 2 * M_PI)
		return (1);
	return (0);
}
