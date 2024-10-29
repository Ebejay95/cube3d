/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 11:12:25 by ajehle            #+#    #+#             */
/*   Updated: 2024/10/29 11:12:50 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	check_leaks(void)
{
	system("leaks cub3D");
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
		return (ft_printf(RED"Error init window\n"D), call_exit(&game), 0);
	start_game(&game);
	call_exit(&game);
	return (0);
}
