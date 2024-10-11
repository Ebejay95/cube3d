/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   audio_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:39:35 by jeberle           #+#    #+#             */
/*   Updated: 2024/10/11 14:17:44 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/cub3d_bonus.h"

void	*door_sound(void *arg)
{
	(void)arg;
	if (access("assets/audio/open.mp3", F_OK) != -1)
	{
		if (fork() == 0)
		{
			execlp("afplay", "afplay", "assets/audio/open.mp3", (char *) NULL);
			_exit(1);
		}
	}
	else
	{
		ft_printf("The file 'assets/audio/open.mp3' does not exist.\n");
	}
	return (NULL);
}

void	play_music(char *cmd)
{
	execlp(cmd, cmd, "-v", "0.4", "assets/audio/cub3d.mp3", (char *) NULL);
	perror("execlp failed");
	_exit(1);
}

void	*bg_music_loop(t_game *g, char *cmd)
{
	while (g->run_music)
	{
		g->music_pid = fork();
		if (g->music_pid == 0)
		{
			play_music(cmd);
		}
		g->bg_sec = 0;
		while (g->bg_sec < 77)
		{
			if (!g->run_music)
				break ;
			sleep(1);
			g->bg_sec++;
		}
	}
	return (NULL);
}

void	*bg_music(void *arg)
{
	t_game	*g;

	g = (t_game *)arg;
	if (access("assets/audio/cub3d.mp3", F_OK) != -1)
		bg_music_loop(g, "afplay");
	else
		ft_printf("The file 'assets/audio/cub3d.mp3' does not exist.\n");
	return (NULL);
}

void	play_sound(pthread_t thread, void *(*play)(void *))
{
	pthread_create(&thread, NULL, play, NULL);
	pthread_join(thread, NULL);
}
