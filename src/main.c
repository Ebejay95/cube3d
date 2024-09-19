/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 11:12:25 by ajehle            #+#    #+#             */
/*   Updated: 2024/09/19 10:21:20 by ajehle           ###   ########.fr       */
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
	char* map_as_string = "1111111111\n1P00000001\n1000001001\n1000000001\n1000000001\n1000000001\n1111100001\n1000000001\n1111111111";
	atexit(check_leaks);
	t_game*	game;

	game = NULL;
	game = ft_initialize(map_as_string);
	if (!game)
		return (ft_printf("Error initialize\n"), call_exit(game), 0);
	// TODO
	// if(assign_data())
	// 	return (ft_printf("Error assign data\n"), call_exit(game), 0);
	if (!ft_init_window(game))
		return (ft_printf("Error init window\n"), call_exit(game), 0);
	if (load_textures(game))
		return (ft_printf("Error\nLoading textures \n"), 0);
	start_game(game);
	call_exit(game);
	return (0);
}



