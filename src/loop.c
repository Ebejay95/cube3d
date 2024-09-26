/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 12:21:52 by ajehle            #+#    #+#             */
/*   Updated: 2024/09/25 17:02:12 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

float	calculate_steps(float dx, float dy)
{
	if (fabsf(dx) > fabsf(dy))
		return (fabsf(dx));
	else
		return (fabsf(dy));
}

void	initialize_ray(t_game *game, int hitx, int hity, t_ray *ray)
{
	ray->start_x = game->player->x * (MCELL / (float)CELL);
	ray->start_y = game->player->y * (MCELL / (float)CELL);
	ray->end_x = hitx * (MCELL / (float)CELL);
	ray->end_y = hity * (MCELL / (float)CELL);
	ray->dx = ray->end_x - ray->start_x;
	ray->dy = ray->end_y - ray->start_y;
	ray->steps = calculate_steps(ray->dx, ray->dy);
	ray->x_inc = ray->dx / ray->steps;
	ray->y_inc = ray->dy / ray->steps;
}

void	draw_pixel(mlx_image_t *image, float x, float y, uint32_t color)
{
	if (x >= 0 && x < image->width && y >= 0 && y < image->height)
	{
		mlx_put_pixel(image, (uint32_t)x, (uint32_t)y, color);
	}
}

void	draw_ray(t_game *game, int hitx, int hity)
{
	t_ray		ray;
	float		x;
	float		y;
	int			i;
	mlx_image_t	*image;

	initialize_ray(game, hitx, hity, &ray);
	image = game->minimap->overlay;
	x = ray.start_x;
	y = ray.start_y;
	i = 0;
	while (i <= ray.steps)
	{
		draw_pixel(image, x, y, RAY_COLOR);
		x += ray.x_inc;
		y += ray.y_inc;
		i++;
	}
}

void	initialize_ray_data(t_game *game, t_ray_data *ray)
{
	ray->posx = game->player->x;
	ray->posy = game->player->y;
	ray->dirx = game->minimap->deltax;
	ray->diry = game->minimap->deltay;
	ray->deltadistx = fabs(1 / ray->dirx);
	ray->deltadisty = fabs(1 / ray->diry);
	ray->mapx = (int)ray->posx;
	ray->mapy = (int)ray->posy;
	ray->hit = 0;
}

void	calculate_step_and_sidedist(t_ray_data *ray)
{
	if (ray->dirx < 0)
	{
		ray->stepx = -1;
		ray->sidedistx = (ray->posx - ray->mapx) * ray->deltadistx;
	}
	else
	{
		ray->stepx = 1;
		ray->sidedistx = (ray->mapx + 1.0 - ray->posx) * ray->deltadistx;
	}
	if (ray->diry < 0)
	{
		ray->stepy = -1;
		ray->sidedisty = (ray->posy - ray->mapy) * ray->deltadisty;
	}
	else
	{
		ray->stepy = 1;
		ray->sidedisty = (ray->mapy + 1.0 - ray->posy) * ray->deltadisty;
	}
}

void	perform_dda(t_game *game, t_ray_data *ray)
{
	while (ray->hit == 0)
	{
		if (ray->sidedistx < ray->sidedisty)
		{
			ray->sidedistx += ray->deltadistx;
			ray->mapx += ray->stepx;
		}
		else
		{
			ray->sidedisty += ray->deltadisty;
			ray->mapy += ray->stepy;
		}
		if (get_cellchar(game, ray->mapx, ray->mapy) == '1')
			ray->hit = 1;
	}
}




int	ft_surface(t_game *game)
{
	if (game->surface)
		mlx_delete_image(game->mlx, game->surface);
	game->surface = mlx_new_image(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!game->surface)
		return (1);
	if (mlx_image_to_window(game->mlx, game->surface, 0, 0) == -1)
		return (1);
	ft_set_color_minimap_char(game->surface, 0x000001);
	return (0);
}

float to_radian(float angle)
{
	return ((angle / 180)  * PI);
}

void	rendering(t_game *game, int hitx, int hity, float angle, int x)
{
	int lenx = hitx - game->player->x;
	int leny = hity - game->player->y;
	float rend_len;
	float len = sqrt((pow(abs(lenx), 2)) + (pow(abs(leny), 2)));
	rend_len = fabs(len * cos(to_radian(180 - angle)));
	// printf("ANGLE:%f X:%d Y:%d SQRT	[%f] \n",angle, abs(lenx), abs(leny), rend_len);


	float start_height = WINDOW_HEIGHT / 2 - BLOCK_HEIGHT / rend_len;
	float end_height = WINDOW_HEIGHT / 2 + BLOCK_HEIGHT / rend_len;
	int	y = start_height;
	// printf("start height:%f end height:%f\n",start_height, end_height);
	while (y < end_height)
	{
		draw_pixel(game->surface , x, y, WALL_COLOR2);
		y++;
	}
}


void	dda_raycast(t_game *game, int *hitx, int *hity)
{
	t_ray_data	ray;

	initialize_ray_data(game, &ray);
	calculate_step_and_sidedist(&ray);
	perform_dda(game, &ray);
	*hitx = ray.mapx;
	*hity = ray.mapy;
}

float	angle_check(float angle)
{
	if (angle > 2 * PI)
		return(angle - 2 * PI);
	else if (angle < 0)
		return(angle + 2 * PI);
	else
		return (angle);
}

int	draw_direction(t_game *game)
{
	float	start_angle;
	float	current_angle;
	int		i;
	int		hitx;
	int		hity;
	i = 0;
	if (ft_surface(game))
		return (1);
	if (ft_overlay(game))
		return (1);
	start_angle = game->player->angle - (FOV / 2);
	float	angle_begin = -45.0;
	while (i <= NUM_RAYS)
	{
		current_angle = start_angle + i * RAY_ANGLE_STEP;
		current_angle = angle_check(current_angle);
		game->minimap->deltax = cos(current_angle);
		game->minimap->deltay = sin(current_angle);
		dda_raycast(game, &hitx, &hity);
		draw_ray(game, hitx, hity);

		// printf("Angle begin %f iteration:  %i\n", angle_begin, i);
		i++;
		angle_begin += (90.0f / (float)NUM_RAYS);
		rendering(game, hitx, hity, angle_begin, i);

	}
		printf("\n");
	return (0);
}

void	calc_delta(t_game *game, char operator)
{
	float	angle_increment;

	angle_increment = 0.1;
	if (operator == '+')
		game->player->angle = angle_check(game->player->angle + angle_increment);
	else if (operator == '-')
		game->player->angle = angle_check(game->player->angle - angle_increment);
	game->minimap->deltax = cos(game->player->angle);
	game->minimap->deltay = sin(game->player->angle);
	game->minimap->angle = game->player->angle;
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;
	bool	is_pressed;

	game = (t_game *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(game->mlx);
	is_pressed = (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT);
	if (keydata.key == MLX_KEY_W)
		game->key_states.w_pressed = is_pressed;
	else if (keydata.key == MLX_KEY_S)
		game->key_states.s_pressed = is_pressed;
	else if (keydata.key == MLX_KEY_A)
		game->key_states.a_pressed = is_pressed;
	else if (keydata.key == MLX_KEY_D)
		game->key_states.d_pressed = is_pressed;
	else if (keydata.key == MLX_KEY_LEFT)
		game->key_states.left_pressed = is_pressed;
	else if (keydata.key == MLX_KEY_RIGHT)
		game->key_states.right_pressed = is_pressed;
}

void	update_game_state(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (game->key_states.w_pressed)
		check_move_up(game);
	if (game->key_states.s_pressed)
		check_move_down(game);
	if (game->key_states.a_pressed)
		check_move_left(game);
	if (game->key_states.d_pressed)
		check_move_right(game);
	if (game->key_states.left_pressed)
		calc_delta(game, '-');
	if (game->key_states.right_pressed)
		calc_delta(game, '+');
	draw_direction(game);
}

void	start_game(t_game *game)
{
	if (game)
	{
		mlx_set_setting(MLX_STRETCH_IMAGE, 1);
		mlx_key_hook(game->mlx, &key_hook, game);
		mlx_loop_hook(game->mlx, &update_game_state, game);
		mlx_loop(game->mlx);
		mlx_terminate(game->mlx);
	}
}
