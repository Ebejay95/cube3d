/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:09:56 by ajehle            #+#    #+#             */
/*   Updated: 2024/09/19 09:16:21 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "cub3d.h"

typedef struct s_map
{
	char*			map_as_string;
	char**			map_as_arr;
	int				width;
	int				height;
}					t_map;

typedef struct s_mini
{
	mlx_image_t*	image;
	mlx_image_t*	img_dir;
	mlx_image_t*	overlay;
	int				width;
	int				height;
	int			pos_x;
	int			pos_y;
	float		delta_x;
	float		delta_y;
	float		angle;
}					t_mini;


typedef struct s_game
{
	t_map*			map;
	t_mini*			minimap;
	mlx_t*			mlx;
}					t_game;

#endif
