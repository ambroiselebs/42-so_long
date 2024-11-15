/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberenge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:26:58 by aberenge          #+#    #+#             */
/*   Updated: 2024/11/15 06:40:06 by aberenge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "mlx.h"
#include "src/init/init.h"
#include "src/exit_game/exit.h"
#include "src/map/map.h"
#include "src/player/player.h"
#include <fcntl.h>
#include "ft_printf.h"

void	first_init(t_game *game, t_player *player, int argc, char **argv)
{
	check_args(argc, argv);
	init_map(argv[1], game);
	init_window(game);
	init_player(game, player);
	draw_map(game, player);
}

int	main(int argc, char **argv)
{
	t_game						game;
	t_player					player;
	t_exit_game_params			exit_params;
	t_player_movement_params	player_movement_params;

	first_init(&game, &player, argc, argv);
	player_movement_params.game = &game;
	player_movement_params.player = &player;
	mlx_key_hook(game.mlx_win, handle_player_movement, &player_movement_params);
	exit_params.player = &player;
	exit_params.game = &game;
	mlx_hook(game.mlx_win, 17, 1L << 17, exit_game, &exit_params);
	mlx_loop(game.mlx);
	return (0);
}
