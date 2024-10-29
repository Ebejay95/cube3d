/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 23:56:58 by jeberle           #+#    #+#             */
/*   Updated: 2024/10/29 11:55:44 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/cub3d_bonus.h"

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
