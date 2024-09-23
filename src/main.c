/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 11:12:25 by ajehle            #+#    #+#             */
/*   Updated: 2024/09/23 16:21:21 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/cub3d.h"

void	check_leaks(void)
{
	system("leaks cub3d");
}

int	main(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	atexit(check_leaks);
	t_game	game;

	ft_initialize(&game, argc, argv);
	if (!game.map)
	{
		call_exit(&game);
		return (1);
	}
	//if (!ft_init_window(&game))
	//	return (ft_printf("Error init window\n"), call_exit(&game), 0);
	//if (load_textures(&game))
	//	return (ft_printf("Error\nLoading textures \n"), 0);
	//start_game(&game);
	call_exit(&game);
	return (0);
}
