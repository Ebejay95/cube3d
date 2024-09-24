/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 11:12:25 by ajehle            #+#    #+#             */
/*   Updated: 2024/09/24 12:06:19 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	check_leaks(void)
{
	system("leaks cub3d");
}

int	main(int argc, char **argv)
{
	t_game	game;

	atexit(check_leaks);
	ft_initialize(&game, argc, argv);
	if (!game.map)
	{
		call_exit(&game);
		return (1);
	}
	if (!ft_init_window(&game))
		return (ft_printf("Error init window\n"), call_exit(&game), 0);
	if (load_textures(&game))
		return (ft_printf("Error\nLoading textures \n"), 0);
	start_game(&game);
	call_exit(&game);
	return (0);
}

/*
TODO
	horizontal intersections
	ys = CELL
	xs = ys / tan(angle)
	yn = player.y - ((player.y/CELL) * CELL)
	xn = yn / tan(angle)

	vertical instersections
	xs = CELL
	ys = xs / tan(angle)
	xn = CELL - ((player.x/CELL) * CELL)
	yn = xn / tan(angle)

	find nearest intersections

*/
