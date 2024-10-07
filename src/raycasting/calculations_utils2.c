/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations_utils2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 11:04:04 by ajehle            #+#    #+#             */
/*   Updated: 2024/10/07 12:49:03 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/********************************************************/
/*	Function to check if angle is within radian values	*/
/********************************************************/
float	angle_check(float angle)
{
	if (angle >= 2 * M_PI)
		return(angle - 2 * M_PI);
	else if (angle < 0)
		return(angle + 2 * M_PI);
	else
		return (angle);
}

float get_min(float a, float b)
{
	if(a <= b)
		return a;
	else
		return b;
}
