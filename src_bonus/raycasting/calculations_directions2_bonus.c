/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations_directions2_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 00:02:23 by jeberle           #+#    #+#             */
/*   Updated: 2024/10/10 00:02:29 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/cub3d_bonus.h"

int	is_looking_north(float angle)
{
	if (angle >= M_PI && angle < (2 * M_PI))
		if (!is_looking_right(angle))
			if (!is_looking_down(angle))
				return (1);
	return (0);
}

int	is_looking_east(float angle)
{
	if (angle >= (M_PI / 2) && angle < (3 * M_PI) / 2)
		if (!is_looking_down(angle))
			if (!is_looking_left(angle))
				return (1);
	return (0);
}

int	is_looking_south(float angle)
{
	if (angle >= 0 && angle < M_PI)
		if (!is_looking_left(angle))
			if (!is_looking_up(angle))
				return (1);
	return (0);
}

int	is_looking_west(float angle)
{
	if (angle >= (M_PI / 2) && angle < (3 * M_PI) / 2)
		if (!is_looking_up(angle))
			if (!is_looking_right(angle))
				return (1);
	return (0);
}
