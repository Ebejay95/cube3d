/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defs_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 00:12:44 by jeberle           #+#    #+#             */
/*   Updated: 2024/10/11 15:33:15 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFS_BONUS_H
# define DEFS_BONUS_H

# include "cub3d_bonus.h"
# include <pthread.h>

# define NORTH 0
# define SOUTH 1
# define EAST 2
# define WEST 3

# define RAY_COLOR 0xDDDDBBFF
# define WALL_COLOR 0x999999FF
# define WALL_COLOR2 0x990099FF
# define WALL_COLOR3 0x999900FF
# define WALL_COLOR4 0x999999FF
# define WALL_COLOR5 0x559999FF
# define ROOM_COLOR 0x000000FF
# define DOOR_COLOR 0x009900FF
# define DOOR_C_CLR 0x990000FF
# define PLAYER_COLOR 0xFF0000FF
# define FRAME_COLOR 0xFFFFFFFF

# define DEBUG 0
# define DEBUG_COLLISION 1
# define PLYR_STEP 6
# define CELL 64
# define MINI_FKT 50
# define MCELL 32
# define PLAYER_SIZE 6
# define PI 3.14159265359
# define NUM_RAYS 1024
# define FOV 60

# define WINDOW_WIDTH 1024
# define WINDOW_HEIGHT 650
# define FRAME_THICKNESS 2

# define FRAME 20

# define NAME_WINDOW "CUB3D"
# define MAP_CNT_CHARS "01 NEWSD\n"
# define MF 250
# define MAX_DOORS 200
# define MAX_DOOR_DISTANCE 120.0
#endif
