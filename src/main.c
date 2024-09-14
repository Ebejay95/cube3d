/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 11:12:25 by ajehle            #+#    #+#             */
/*   Updated: 2024/09/14 12:31:06 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/cub3d.h"

void	check_leaks(void)
{
	system("leaks cub3d");
}

t_mini*	ft_mem_minimap(void)
{
	t_mini*	mini;

	mini = NULL;
	mini = ft_calloc(sizeof(t_mini), 1);
	if (!mini)
		return (NULL);
	return (mini);
}

t_map*	ft_mem_map(void)
{
	t_map*	map;

	map = NULL;
	map = ft_calloc(sizeof(t_map), 1);
	if (!map)
		return (NULL);
}

t_game* mem_management(void)
{
	t_game	*game;
	game = ft_initialize_game();
	if(!game)
		return (ft_printf("Error\n"), call_exit(game), NULL);
	game->minimap = ft_mem_minimap();
	game->map = ft_mem_map();
	if(!game->minimap || !game->map)
		return (ft_printf("Error\n"), call_exit(game), NULL);
	return	game;
}

int	main(int argc, char **argv)
{
	atexit(check_leaks);
	t_map*	map;
	t_game*	game;
	t_mini*	mini;

	map = NULL;
	game = NULL;
	mini = NULL;

	game = mem_management();

	map = ft_initialize_map("1111111111\n1P00000001\n1000001001\n1000000001\n1000000001\n1000000001\n1111100001\n1000000001\n1000000001\n1111111111");
	mini = ft_initialize_minimap(map);
	// game = ft_init(map, mini);

	start_game(game);
	call_exit(game);
	return (0);
}



