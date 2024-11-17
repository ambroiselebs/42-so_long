/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_gesture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberenge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 06:18:44 by aberenge          #+#    #+#             */
/*   Updated: 2024/11/17 01:55:17 by aberenge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include "ft_printf.h"
#include "../exit_game/exit.h"
#include "mlx.h"

void	perform_movement(t_game *game, t_player *player, t_player_perform *cord)
{
	game->map[cord->new_y][cord->new_x] = 'P';
	game->map[player->pos_y][player->pos_x] = '0';
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		player->skin,
		cord->new_x * game->tile_size,
		cord->new_y * game->tile_size);
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->ground_sprite,
		player->pos_x * game->tile_size,
		player->pos_y * game->tile_size);
	player->pos_x = cord->new_x;
	player->pos_y = cord->new_y;
}

void	handle_collision(t_game *game, t_player *player, int new_x, int new_y)
{
	t_player_perform	cord;
	t_exit_game_params	exit_params;

	cord.new_x = new_x;
	cord.new_y = new_y;
	if (game->map[new_y][new_x] != '1')
	{
		if (game->map[new_y][new_x] == 'E' && player->coins == game->total_coin)
		{
			exit_params.game = game;
			exit_params.player = player;
			exit_game(&exit_params);
		}
		else if (game->map[new_y][new_x] == 'E'
			&& player->coins != game->total_coin)
			return ;
		else if (game->map[new_y][new_x] == 'C')
			player->coins++;
		perform_movement(game, player, &cord);
	}
}

int	handle_player_movement(int key, t_player_movement_params *params)
{
	t_exit_game_params	exit_params;
	int					new_x;
	int					new_y;

	if (key == 65307)
	{
		exit_params.game = params->game;
		exit_params.player = params->player;
		exit_game(&exit_params);
	}
	params->player->movement_count++;
	if (params->player->movement_count > 0)
		ft_printf("Ta bouger %d fois\n", params->player->movement_count);
	new_x = params->player->pos_x;
	new_y = params->player->pos_y;
	if (key == 'w')
		handle_collision(params->game, params->player, new_x, new_y - 1);
	if (key == 's')
		handle_collision(params->game, params->player, new_x, new_y + 1);
	if (key == 'a')
		handle_collision(params->game, params->player, new_x - 1, new_y);
	if (key == 'd')
		handle_collision(params->game, params->player, new_x + 1, new_y);
	return (0);
}
