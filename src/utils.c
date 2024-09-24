/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 12:13:18 by ajehle            #+#    #+#             */
/*   Updated: 2024/09/24 15:53:20 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_collision(t_game *game, int new_x, int new_y)
{
	int	player_radius;

	player_radius = (PLAYER_SIZE / 2) + 1;
	if (get_cellchar(game, new_x - player_radius, new_y - player_radius) == '1')
		return (1);
	if (get_cellchar(game, new_x + player_radius, new_y - player_radius) == '1')
		return (1);
	if (get_cellchar(game, new_x - player_radius, new_y + player_radius) == '1')
		return (1);
	if (get_cellchar(game, new_x + player_radius, new_y + player_radius) == '1')
		return (1);
	return (0);
}

void	print_2d_arr(char **map_in_arr)
{
	int	i;
	int	j;

	if (!map_in_arr)
		return ;
	i = 0;
	j = 0;
	ft_printf("	[0][1][2][3][4][5][6][7][8][9][10]\n");
	while (map_in_arr[i])
	{
		ft_printf("[%i]	", i);
		while (map_in_arr[i][j])
		{
			ft_printf(" %c ", map_in_arr[i][j]);
			j++;
		}
		ft_printf("\n");
		j = 0;
		i++;
	}
}

char	get_cellchar(t_game *game, int x, int y)
{
	int	cell_x;
	int	cell_y;

	cell_x = x / CELL;
	cell_y = y / CELL;
	return (game->map->content[cell_y][cell_x]);
}

// t_pos	*get_pos_unique(char **content, char c)
// {
// 	t_pos	*pos;
// 	int		x;
// 	int		y;

// 	pos = NULL;
// 	y = 0;
// 	pos = ft_calloc(1, sizeof(t_pos));
// 	if (!pos)
// 		return (NULL);
// 	while (content[y])
// 	{

// 		x = 0;
// 		while (content[y][x])
// 		{
// 			if (content[y][x] == c)
// 				return (pos->x = x, pos->y = y, pos);
// 			x++;
// 		}
// 		y++;
// 	}
// 	return (pos);
// }
