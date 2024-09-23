/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_printers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:33:25 by jeberle           #+#    #+#             */
/*   Updated: 2024/09/23 16:16:22 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_printmetas(t_map *map)
{
	ft_printf("\nTexture Pointers:\n");
	ft_printf("West: %p\n", (void *)map->tex_west);
	ft_printf("East: %p\n", (void *)map->tex_east);
	ft_printf("North: %p\n", (void *)map->tex_north);
	ft_printf("South: %p\n", (void *)map->tex_south);
	ft_printf("\nImage Pointers:\n");
	ft_printf("West: %p\n", (void *)map->img_west);
	ft_printf("East: %p\n", (void *)map->img_east);
	ft_printf("North: %p\n", (void *)map->img_north);
	ft_printf("South: %p\n", (void *)map->img_south);
	ft_printf("\nColors:\n");
	ft_printf("Ceiling: 0x%08X\n", map->ceiling);
	ft_printf("Floor: 0x%08X\n", map->floor);
	ft_printf("\nFlags:\n");
	ft_printf("Ceiling set: %d\n", map->ceiling_set);
	ft_printf("Floor set: %d\n", map->floor_set);
	ft_printf(G"------------------------------------\n");
	ft_printf("MAP VALID >>> START GAME\n");
	ft_printf("------------------------------------\n\n"D);
}

void	print_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	if (!map)
		return ;
	if (map->content)
	{
		while (map->content[i])
		{
			j = 0;
			while (map->content[i][j])
			{
				ft_printf(G"%c"D, map->content[i][j]);
				j++;
			}
			ft_printf("\n");
			i++;
		}
	}
	ft_printmetas(map);
}

void	print_map_error(t_map *map, int ey, int ex)
{
	int	i;
	int	j;

	i = 0;
	if (map->content)
	{
		while (map->content[i])
		{
			j = 0;
			while (map->content[i][j])
			{
				if (i == ey && j == ex)
					ft_fprintf(2, RED"%c"D, map->content[i][j]);
				else
					ft_fprintf(2, B"%c"D, map->content[i][j]);
				j++;
			}
			ft_fprintf(2, "\n");
			i++;
		}
	}
}
