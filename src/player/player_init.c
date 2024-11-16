/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberenge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 05:14:36 by aberenge          #+#    #+#             */
/*   Updated: 2024/11/16 21:37:41 by aberenge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include "mlx.h"
#include "ft_printf.h"
#include <stdlib.h>

void	load_player_skin(t_game *game, t_player *player)
{
	player->skin = mlx_xpm_file_to_image(game->mlx, "assets/player.xpm",
			&game->tile_size, &game->tile_size);
}

void	locate_player(t_game *game, t_player *player)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->win_height)
	{
		x = 0;
		while (x < game->win_width)
		{
			if (game->map[y][x] == 'P')
			{
				player->pos_x = x;
				player->pos_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	init_player(t_game *game, t_player *player)
{
	locate_player(game, player);
	load_player_skin(game, player);
	player->coins = 0;
	player->movement_count = 0;
}
