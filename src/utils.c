/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 12:13:18 by ajehle            #+#    #+#             */
/*   Updated: 2024/09/23 16:58:56 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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
