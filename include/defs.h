/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:10:55 by ajehle            #+#    #+#             */
/*   Updated: 2024/09/20 11:33:21 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFS_H
# define DEFS_H

# include "cub3d.h"

# define DEBUG 0
# define PIXEL 64
# define PLAYER_STEP 1
# define PIXEL_MINI 32
# define PIXEL_MINI_CHAR (PIXEL_MINI / 2)
# define CELLSIZE 64
# define OFFSET 4
# define PI 3.14159265359

# define WINDOW_WIDTH 1000
# define WINDOW_HEIGHT 650

# define FRAME 20

# define NAME_WINDOW "CUB3D"
# define PATH_PLAYER "./assets/32x32/knight.png"
# define PATH_FLOOR "./assets/32x32/floor_1.png"
# define PATH_OBSTACLE "./assets/32x32/wall_1.png"
# define PATH_EXIT_CLOSED "./assets/32x32/floor_2.png"
# define PATH_EXIT_OPEN "./assets/32x32/stair_nextlevel.png"
# define PATH_ITEM "./assets/32x32/key_silver.png"
# define PATH_ENEMY "./assets/32x32/ghost.png"

#endif
