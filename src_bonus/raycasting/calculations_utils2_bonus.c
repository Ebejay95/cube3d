/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations_utils2_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 00:01:47 by jeberle           #+#    #+#             */
/*   Updated: 2024/10/10 00:01:53 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/cub3d_bonus.h"

/********************************************************/
/*	Function to check if angle is within radian values	*/
/********************************************************/
float	angle_check(float angle)
{
	if (angle >= 2 * M_PI)
		return (angle - 2 * M_PI);
	else if (angle < 0)
		return (angle + 2 * M_PI);
	else
		return (angle);
}

float	get_min(float a, float b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}
