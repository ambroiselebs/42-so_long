/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberenge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 20:44:38 by aberenge          #+#    #+#             */
/*   Updated: 2024/12/05 16:34:59 by aberenge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "mlx.h"
#include "ft_printf.h"
#include "../exit_game/exit.h"
#include <stdlib.h>

void	init_window(t_game *game)
{
	game->coin_found = 0;
	game->exit_found = 0;
	game->player_found = 0;
	game->tile_size = 32;
	game->total_coin = 0;
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx,
			game->win_width * game->tile_size,
			game->win_height * game->tile_size,
			"so_long");
	game->ground_sprite = mlx_xpm_file_to_image(game->mlx,
			"assets/ground.xpm", &game->tile_size, &game->tile_size);
	game->wall_sprite = mlx_xpm_file_to_image(game->mlx,
			"assets/wall.xpm", &game->tile_size, &game->tile_size);
	game->coin_sprite = mlx_xpm_file_to_image(game->mlx,
			"assets/coin.xpm", &game->tile_size, &game->tile_size);
	game->exit_sprite = mlx_xpm_file_to_image(game->mlx,
			"assets/exit.xpm", &game->tile_size, &game->tile_size);
}
