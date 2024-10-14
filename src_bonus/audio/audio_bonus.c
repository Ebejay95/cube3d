/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   audio_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:39:35 by jeberle           #+#    #+#             */
/*   Updated: 2024/10/14 20:44:09 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/cub3d_bonus.h"

void	*door_close(void *arg)
{
	(void)arg;
	if (access("assets/audio/close.mp3", F_OK) != -1)
	{
		if (fork() == 0)
		{
			execlp("afplay", "afplay", "assets/audio/close.mp3", (char *) NULL);
			_exit(1);
		}
	}
	else
	{
		ft_printf("The file 'assets/audio/close.mp3' does not exist.\n");
	}
	return (NULL);
}

void	*door_open(void *arg)
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

void	*good(void *arg)
{
	(void)arg;
	if (access("assets/audio/good.mp3", F_OK) != -1)
	{
		if (fork() == 0)
		{
			execlp("afplay", "afplay", "assets/audio/good.mp3", (char *) NULL);
			_exit(1);
		}
	}
	else
	{
		ft_printf("The file 'assets/audio/good.mp3' does not exist.\n");
	}
	return (NULL);
}

void	play_sound(pthread_t thread, void *(*play)(void *))
{
	pthread_create(&thread, NULL, play, NULL);
	pthread_join(thread, NULL);
}
