/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:56:22 by ajehle            #+#    #+#             */
/*   Updated: 2024/09/26 16:37:49 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// Draw the wall slice on the screen
void draw_wall(mlx_image_t *surface, int x, float start_height, float end_height)
{
	int y = (int)start_height;
	while (y < (int)end_height)
	{
		mlx_put_pixel(surface, x, y, WALL_COLOR2);
		y++;
	}
}




// Calculate the corrected distance for rendering
float calculate_distance(float player_x, float player_y, int hitx, int hity, float ray_angle)
{
	float lenx = hitx - player_x;
	float leny = hity - player_y;
	float distance = sqrt(pow(lenx, 2) + pow(leny, 2));

	// Correct for the fisheye effect by adjusting the distance with the ray angle
	return distance * cos(to_radian(180 - ray_angle));
}

// Calculate the height of the wall slice to render
void calculate_wall_slice_height(float distance, float *start_height, float *end_height)
{
	float height = BLOCK_HEIGHT / distance;
	*start_height = (WINDOW_HEIGHT / 2) - height / 2;
	*end_height = (WINDOW_HEIGHT / 2) + height / 2;
}


// Render a single wall slice based on the hit coordinates
void render_wall_slice(t_game *game, int hitx, int hity, int ray_index, float ray_angle)
{
	// Calculate the distance from the player to the wall hit point
	float distance = calculate_distance(game->player->x, game->player->y, hitx, hity, ray_angle);

	// Calculate the wall slice height to render based on the distance
	float start_height, end_height;
	calculate_wall_slice_height(distance, &start_height, &end_height);

	// Render the wall slice by drawing vertical pixels
	draw_wall(game->surface, ray_index, start_height, end_height);
}


// Initialize ray data (position and direction)
void initialize_ray(t_game *game, t_ray_data *ray, float ray_angle)
{
	ray->posx = game->player->x;
	ray->posy = game->player->y;

	ray->dirx = cos(ray_angle);
	ray->diry = sin(ray_angle);

	ray->deltadistx = fabs(1 / ray->dirx);
	ray->deltadisty = fabs(1 / ray->diry);

	ray->mapx = (int)ray->posx;
	ray->mapy = (int)ray->posy;

	ray->hit = 0;  // Ray hasn't hit anything yet
}



// Function to cast a single ray and return hit coordinates
void cast_ray(t_game *game, float ray_angle, int *hitx, int *hity)
{
	t_ray_data ray;
	initialize_ray(game, &ray, ray_angle);    // Initialize ray starting position and direction
	calculate_steps_and_sidedist(&ray);       // Calculate step directions and side distances
	perform_dda(game, &ray);                  // Perform the DDA algorithm

	// Store hit coordinates
	*hitx = ray.mapx;
	*hity = ray.mapy;
}

// Renders the game by casting rays and rendering walls
int render_game(t_game *game)
{
	float start_angle = game->player->angle - (FOV / 2);
	float current_angle;
	int ray_index = 0;
	// float angle_step = 90.0f / (float)NUM_RAYS;

	// Cast rays for the entire field of view
	while (ray_index < NUM_RAYS)
	{
		current_angle = start_angle + ray_index * RAY_ANGLE_STEP;
		current_angle = angle_check(current_angle);

		// Cast a ray and get hit coordinates
		int hitx, hity;
		cast_ray(game, current_angle, &hitx, &hity);

		// Render the wall slice for this ray
		render_wall_slice(game, hitx, hity, ray_index, current_angle);

		ray_index++;
	}

	return 0;
}
