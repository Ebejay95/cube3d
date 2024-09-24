/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:10:55 by ajehle            #+#    #+#             */
/*   Updated: 2024/09/24 14:31:04 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFS_H
# define DEFS_H

# include "cub3d.h"

# define DEBUG 0
# define DEBUG_COLLISION 1
# define SPEED 5
# define PLYR_STEP 4
# define CELL 64
# define MINI_FKT 50
# define PLAYER_SIZE 4
# define MCELL (CELL)/(100 / MINI_FKT)
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

# define MAP_CNT_CHARS "01 NEWS\n"
#endif
