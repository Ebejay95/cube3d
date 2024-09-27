/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:10:55 by ajehle            #+#    #+#             */
/*   Updated: 2024/09/27 14:00:20 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFS_H
# define DEFS_H

# include "cub3d.h"

# define RAY_COLOR 0xDDDDBBFF
# define WALL_COLOR 0x999999FF
# define WALL_COLOR2 0x990099FF
# define WALL_COLOR3 0x999900FF
# define ROOM_COLOR 0x000000FF
# define PLAYER_COLOR 0xFF0000FF
# define FRAME_COLOR 0xFFFFFFFF

# define DEBUG 0
# define DEBUG_COLLISION 1
# define PLYR_STEP 2
# define CELL 64
# define MINI_FKT 50
# define MCELL 32
# define PLAYER_SIZE 6
# define PI 3.14159265359
# define NUM_RAYS 1024
# define FOV (PI / 2)
# define FOV_RAD (FOX * PI) / 180
# define RAY_ANGLE_STEP (FOV / (float)NUM_RAYS)

# define WINDOW_WIDTH 1024
# define WINDOW_HEIGHT 650
# define FRAME_THICKNESS 2

// Test Blockheight:
#define BLOCK_HEIGHT 4000

# define FRAME 20

# define NAME_WINDOW "CUB3D"
# define PATH_PLAYER "./assets/32x32/knight.png"
# define PATH_FLOOR "./assets/32x32/floor_1.png"
# define PATH_OBSTACLE "./assets/32x32/wall_1.png"
# define PATH_EXIT_CLOSED "./assets/32x32/floor_2.png"
# define PATH_EXIT_OPEN "./assets/32x32/stair_nextlevel.png"
# define PATH_ITEM "./assets/32x32/key_silver.png"
# define PATH_ENEMY "./assets/32x32/ghost.png"

# define MAP_CNT_CHARS "01 NEWS\n"
# define MAP_FRAME 250

#endif
