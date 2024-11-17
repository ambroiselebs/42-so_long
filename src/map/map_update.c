/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberenge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 05:24:24 by aberenge          #+#    #+#             */
/*   Updated: 2024/11/17 02:40:45 by aberenge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "mlx.h"
#include "ft_printf.h"
#include "../exit_game/exit.h"

void	check_player(int *player_spawn, t_game *game, t_player *player)
{
	t_exit_game_params	params;

	params.game = game;
	params.player = player;
	if (*player_spawn > 0)
	{
		ft_printf("Error\nToo many player spawn\n");
		exit_game(&params);
	}
	(*player_spawn)++;
}

void	check_exit(int *exit, t_game *game, t_player *player)
{
	t_exit_game_params	params;

	params.game = game;
	params.player = player;
	if (*exit > 0)
	{
		ft_printf("Error\nToo exit point\n");
		exit_game(&params);
	}
	(*exit)++;
}

void	check_map(t_game *game, t_player *player)
{
	int	x;
	int	y;
	int	player_spawn;
	int	exit;

	y = 0;
	player_spawn = 0;
	exit = 0;
	while (y < game->win_height)
	{
		x = 0;
		while (x < game->win_width)
		{
			if (game->map[y][x] == 'P')
				check_player(&player_spawn, game, player);
			if (game->map[y][x] == 'E')
				check_exit(&exit, game, player);
			x++;
		}
		y++;
	}
}

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

	check_map(game, player);
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
