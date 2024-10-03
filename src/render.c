/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:21:03 by ajehle            #+#    #+#             */
/*   Updated: 2024/10/03 16:38:01 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/cub3d.h"


int	ft_load_map(t_game *game, char c, int color)
{
	int				x;
	int				y;
	// mlx_image_t		*image;

	x = 0;
	y = 0;
	// image = mlx_new_image(game->mlx, MCELL - 1, MCELL - 1);
	// if (!image)
	// 	return (1);
	(void) c;
	ft_set_color_minimap_char(game->surface, color);
	while (x < game->map->width)
	{
		y = 0;
		while (y < game->map->height)
		{
			if (game->map->content[y] && game->map->content[y][x] == c)
			{
				// if (mlx_image_to_window(game->mlx, game->surface, x * MCELL, y * MCELL) == -1)
				if (mlx_image_to_window(game->mlx, game->surface, x, y ) == -1)
					return (1);
			}
			y++;
		}
		x++;
	}
	return (0);
}


// float find_horizontal(t_game* game)
// {
//     float horizontal;
//     float vertical;

//     // Determine whether the ray is facing up or down based on the angle
//     if (game->player->angle >= M_PI)
//         horizontal = ((int)(game->player->y / CELL)) * CELL - 0.0001;  // Adjust for downward facing ray
//     else
//         horizontal = ((int)(game->player->y / CELL)) * CELL + CELL;    // Adjust for upward facing ray
//     // Clamp horizontal to stay within the map's boundaries
//     if (horizontal < CELL)
//         horizontal = CELL;  // Clamp to the top boundary
//     else if (horizontal > game->map->height * CELL)
//         horizontal = game->map->height * CELL;  // Clamp to the bottom boundary

//     // Handle cases where the player is looking directly left or right (angle ≈ π or 0)
//     if (fabs(game->player->angle - M_PI) < 0.0001)  // Player looking West (≈ 180 degrees)
//     {
//         vertical = 0;  // Since ray is parallel to the x-axis, no valid vertical hit
//     }
//     // else if (fabs(game->player->angle) < 0.0001 || fabs(game->player->angle - 2 * M_PI) < 0.0001)  // Looking East (≈ 0 or 360 degrees)
//     // {
//         // vertical = INFINITY;  // No valid vertical hit when looking perfectly east
//     // }
//     else
//     {
//         // Otherwise, calculate vertical normally using tan(angle)
//         vertical = game->player->x + (game->player->y - horizontal) / tan(game->player->angle);
//     }

//     // Clamp vertical to stay within the map's boundaries
//     if (vertical < CELL)
//         vertical = CELL;  // Clamp to the left boundary
//     else if (vertical > game->map->width * CELL)
//         vertical = game->map->width * CELL;  // Clamp to the right boundary


//     printf("X%f Y%f A%f H%f V%f\n", game->player->x, game->player->y, game->player->angle, horizontal, vertical);
// 	// ft_load_map(game, 1, 0x00FF00FF);
// 	// mlx_put_pixel(game->surface, vertical  , horizontal , PLAYER_COLOR); // Choose a color for the grid lines

//     return horizontal;
// }

int is_wall(int grid_x, int grid_y, t_game* game) {
    // For simplicity, assume there's a wall at grid (2, 0)
	if(game->map->content[grid_y][grid_x])
    {
        return 1; // Wall is present
    }
    return 0; // No wall
}

void horizontal(t_game* game)
{
	float A_x, A_y, C_x, C_y, D_x, D_y;
	int grid_x, grid_y;
	float Ya, Xa;
	int	look_up =game->player->angle > PI && game->player->angle < 2 * PI;

	// Finding A.y
	if (look_up) //if player is looking up
	{
	printf("Player is loooking up\n");

		// A_y = fabs(game->player->y / CELL) * CELL - 1;
		A_y = floor(game->player->y / CELL) * CELL - 0.0001;
	}
	else
	{
		A_y = floor(game->player->y / CELL) * CELL + CELL;
	}
	// Clamp vertical to stay within the map's boundaries
	if (A_y < CELL)
		A_y = CELL;  // Clamp to the left boundary
	else if (A_y > game->map->width * CELL)
		A_y = game->map->width * CELL;  // Clamp to the right boundary

	// Finding A.x
	A_x = game->player->x + (game->player->y - A_y) / tan(game->player->angle);
	// A_x = game->player->x + (game->player->y - A_y) / tan(game->player->angle);
		// Clamp horizontal to stay within the map's boundaries
	if (A_x < CELL)
		A_x = CELL;  // Clamp to the top boundary
	else if (A_x > game->map->height * CELL)
		A_x = game->map->height * CELL;  // Clamp to the bottom boundary
	grid_x = (int)(A_x / CELL);
	grid_y = (int)(A_y / CELL);
	printf("A coordinates: A_x = %.2f, A_y = %.2f angle = %.2f\n", A_x, A_y, game->player->angle);
	printf("Grid coordinates of A: (%d, %d)\n", grid_x, grid_y);
	// Finding Ya
	if (look_up)
	{
		Ya = -CELL;
	}
	else
	{
		Ya = CELL;
	}

	// Finding Xa
	Xa = CELL / tan(game->player->angle);

	// Finding C coordinates
	C_x = A_x + Xa;
	C_y = A_y + Ya;

	// Finding grid coordinates of C
	grid_x = (int)(C_x / CELL);
	grid_y = (int)(C_y / CELL);

	printf("C coordinates: C_x = %.2f, C_y = %.2f\n", C_x, C_y);
	printf("Grid coordinates of C: (%d, %d)\n", grid_x, grid_y);

	// Check if there's a wall at C
	if (is_wall(grid_x, grid_y, game)) {
		printf("Wall found at C, stopping.\n");
		return;
	}

		// Finding D coordinates
	D_x = C_x + Xa;
	D_y = C_y + Ya;

	// Finding grid coordinates of D
	grid_x = (int)(D_x / CELL);
	grid_y = (int)(D_y / CELL);

	printf("D coordinates: D_x = %.2f, D_y = %.2f\n", D_x, D_y);
	printf("Grid coordinates of D: (%d, %d)\n", grid_x, grid_y);
	return;
}


int	render(t_game* game)
{
	printf("Y:%.2f X:%.2f A:%.2f\n",game->player->y,game->player->x,game->player->angle);
	// horizontal(game);

	return 0;
}
