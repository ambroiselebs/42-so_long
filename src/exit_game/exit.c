/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberenge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 19:09:54 by aberenge          #+#    #+#             */
/*   Updated: 2024/11/17 05:20:31 by aberenge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit.h"
#include <stdlib.h>
#include "mlx.h"
#include "ft_printf.h"

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
	if (params->player->movement_count != -1)
		ft_printf("Total movements : %d\n", params->player->movement_count);
	mlx_destroy_window(params->game->mlx, params->game->mlx_win);
	mlx_destroy_image(params->game->mlx, params->game->ground_sprite);
	mlx_destroy_image(params->game->mlx, params->game->wall_sprite);
	mlx_destroy_image(params->game->mlx, params->game->coin_sprite);
	mlx_destroy_image(params->game->mlx, params->game->exit_sprite);
	mlx_destroy_image(params->game->mlx, params->player->skin);
	mlx_destroy_display(params->game->mlx);
	free_map(params->game);
	free(params->game->mlx);
	exit(0);
	return (0);
}
