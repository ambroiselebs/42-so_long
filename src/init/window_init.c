/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberenge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 20:44:38 by aberenge          #+#    #+#             */
/*   Updated: 2024/11/17 07:30:54 by aberenge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "mlx.h"
#include "ft_printf.h"

void	init_window(t_game *game)
{
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
