/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:21:03 by ajehle            #+#    #+#             */
/*   Updated: 2024/10/04 11:30:25 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/cub3d.h"



void calculate_wall_slice_height(float height, float *bottom, float *top)
{
	*bottom = (WINDOW_HEIGHT / 2) - height / 2;
	*top = (WINDOW_HEIGHT / 2) + height / 2;
	if(*bottom > WINDOW_HEIGHT)
		*bottom = WINDOW_HEIGHT;
	if(*top < 0)
		*top = 0;

}

// void draw_wall(mlx_image_t *surface, int x, float bottom, float top)
// {
// 	int y = (int)bottom;
// 	while (y < (int)top)
// 	{
// 		draw_pixel(surface, x, y, WALL_COLOR2);
// 		y++;
// 	}
// }


void draw_wall(mlx_image_t *surface,int index_of_ray ,int t_pix, int b_pix)
{
	while (t_pix < b_pix)
	{
		// draw_pixel(surface, x, y, WALL_COLOR2);
		mlx_put_pixel(surface, index_of_ray, t_pix, WALL_COLOR2);
		t_pix++;
	}
}

void	rendering_wall(t_game* game, float ray_len, int index_of_ray, float current_angle)
{
	float bottom;
	float top;
	float wall_height;

	ray_len = fish_eye_correction(game, ray_len, current_angle);
	wall_height = (CELL / ray_len) * ((WINDOW_HEIGHT/2) / tan(FOV / 2));
	calculate_wall_slice_height(wall_height, &bottom, &top);

	draw_wall(game->surface, index_of_ray, bottom, top);

}

