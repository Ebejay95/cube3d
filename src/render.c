/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreasjehle <andreasjehle@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:21:03 by ajehle            #+#    #+#             */
/*   Updated: 2024/09/29 10:41:31 by andreasjehl      ###   ########.fr       */
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



float find_horizontal(t_game* game)
{
    float horizontal;
    float vertical;

    // Determine whether the ray is facing up or down based on the angle
    if (game->player->angle >= M_PI)
        horizontal = ((int)(game->player->y / CELL)) * CELL - 0.0001;  // Adjust for downward facing ray
    else
        horizontal = ((int)(game->player->y / CELL)) * CELL + CELL;    // Adjust for upward facing ray

    // Handle cases where the player is looking directly left or right (angle ≈ π or 0)
    if (fabs(game->player->angle - M_PI) < 0.0001)  // Player looking West (≈ 180 degrees)
    {
        vertical = 0;  // Since ray is parallel to the x-axis, no valid vertical hit
    }
    else if (fabs(game->player->angle) < 0.0001 || fabs(game->player->angle - 2 * M_PI) < 0.0001)  // Looking East (≈ 0 or 360 degrees)
    {
        vertical = INFINITY;  // No valid vertical hit when looking perfectly east
    }
    else
    {
        // Otherwise, calculate vertical normally using tan(angle)
        vertical = game->player->x + (game->player->y - horizontal) / tan(game->player->angle);
    }

    // Clamp vertical to stay within the map's boundaries
    if (vertical < CELL)
        vertical = CELL;  // Clamp to the left boundary
    else if (vertical > game->map->width * CELL)
        vertical = game->map->width * CELL;  // Clamp to the right boundary

    // Clamp horizontal to stay within the map's boundaries
    if (horizontal < CELL)
        horizontal = CELL;  // Clamp to the top boundary
    else if (horizontal > game->map->height * CELL)
        horizontal = game->map->height * CELL;  // Clamp to the bottom boundary

    printf("X%f Y%f A%f H%f V%f\n", game->player->x, game->player->y, game->player->angle, horizontal, vertical);
	ft_load_map(game, 1, 0x00FF00FF);
	mlx_put_pixel(game->surface, vertical  , horizontal , PLAYER_COLOR); // Choose a color for the grid lines

    return horizontal;
}


// float find_vertical(t_game* game)
// {
// }

int	render(t_game* game)
{
	float horizontal;
	// float vertical;

	horizontal = find_horizontal(game);
	// vertical = find_vertical(game);

	return(horizontal);
}
