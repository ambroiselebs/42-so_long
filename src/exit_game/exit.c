/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberenge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 19:09:54 by aberenge          #+#    #+#             */
/*   Updated: 2024/11/15 06:40:35 by aberenge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit.h"
#include <stdlib.h>
#include "mlx.h"

void	free_map(t_game *game)
{
	int	i;

	if (game->map != NULL)
	{
		i = 0;
		while (game->map[i] != NULL)
		{
			free(game->map[i]);
			i++;
		}
		free(game->map);
		game->map = NULL;
	}
}

int	exit_game(t_exit_game_params *params)
{
	mlx_destroy_window(params->game->mlx, params->game->mlx_win);
	mlx_destroy_image(params->game->mlx, params->game->ground_sprite);
	mlx_destroy_image(params->game->mlx, params->game->wall_sprite);
	mlx_destroy_image(params->game->mlx, params->player->skin);
	free_map(params->game);
	exit(0);
	return (0);
}
