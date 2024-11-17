/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberenge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 05:24:24 by aberenge          #+#    #+#             */
/*   Updated: 2024/11/17 02:14:21 by aberenge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "mlx.h"
#include "ft_printf.h"

void	put_texture(char c, int pos_x, int pos_y, t_put_texture_params *params)
{
	if (c == 'P')
		mlx_put_image_to_window(params->game->mlx, params->game->mlx_win,
			params->player->skin,
			pos_x * params->game->tile_size,
			pos_y * params->game->tile_size);
	else if (c == '0')
		mlx_put_image_to_window(params->game->mlx, params->game->mlx_win,
			params->game->ground_sprite,
			pos_x * params->game->tile_size,
			pos_y * params->game->tile_size);
	else if (c == '1')
		mlx_put_image_to_window(params->game->mlx, params->game->mlx_win,
			params->game->wall_sprite,
			pos_x * params->game->tile_size,
			pos_y * params->game->tile_size);
	else if (c == 'C')
		mlx_put_image_to_window(params->game->mlx, params->game->mlx_win,
			params->game->coin_sprite,
			pos_x * params->game->tile_size,
			pos_y * params->game->tile_size);
	else if (c == 'E')
		mlx_put_image_to_window(params->game->mlx, params->game->mlx_win,
			params->game->exit_sprite,
			pos_x * params->game->tile_size,
			pos_y * params->game->tile_size);
}

void	draw_map(t_game *game, t_player *player)
{
	t_put_texture_params	put_texture_params;
	int						x;
	int						y;

	y = 0;
	put_texture_params.game = game;
	put_texture_params.player = player;
	while (y < game->win_height)
	{
		x = 0;
		while (x < game->win_width)
		{
			put_texture(game->map[y][x], x, y, &put_texture_params);
			if (game->map[y][x] == 'C')
				game->total_coin++;
			x++;
		}
		y++;
	}
}
