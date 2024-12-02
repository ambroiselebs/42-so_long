/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberenge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:32:55 by aberenge          #+#    #+#             */
/*   Updated: 2024/12/02 13:40:49 by aberenge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "ft_printf.h"
#include "libft.h"
#include "../exit_game/exit.h"

void	count_coins(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->win_height)
	{
		x = 0;
		while (x < game->win_width)
		{
			if (game->map[y][x] == 'C')
				game->total_coin++;
			x++;
		}
		y++;
	}
}

void	send_exit_game(t_game *game, t_player *player)
{
	t_exit_game_params	params;

	params.game = game;
	params.player = player;
	ft_printf("Error\nInvalid map (impossible to complete)\n");
	free_copy(game);
	exit_game(&params);
}

void	flood_fill(t_game *game, int x, int y)
{
	if (y < 0 || y >= game->win_height || x < 0 || x >= game->win_width)
		return ;
	if (game->map_copy[y][x] == '1' || game->map_copy[y][x] == '2')
		return ;
	if (game->map_copy[y][x] == 'C')
		(game->coin_found)++;
	if (game->map_copy[y][x] == 'E')
		game->exit_found = 1;
	if (game->map_copy[y][x] == 'P')
		game->player_found = 1;
	game->map_copy[y][x] = '2';
	flood_fill(game, x + 1, y);
	flood_fill(game, x - 1, y);
	flood_fill(game, x, y + 1);
	flood_fill(game, x, y - 1);
}

void	copy_map(t_game *game)
{
	int		i;
	char	**map_copy;

	map_copy = malloc(sizeof(char *) * (game->win_height + 1));
	if (!map_copy)
	{
		ft_printf("Error\nError while allocating the check map\n");
		exit(0);
	}
	i = -1;
	while (++i < game->win_height)
	{
		map_copy[i] = malloc(sizeof(char) * (game->win_width + 1));
		if (!map_copy[i])
		{
			ft_printf("Error\nError while allocating the check map\n");
			exit(0);
		}
		ft_strlcpy(map_copy[i], game->map[i], game->win_width + 1);
	}
	map_copy[i] = NULL;
	game->map_copy = map_copy;
}

void	check_path(t_game *game, t_player *player)
{
	count_coins(game);
	copy_map(game);
	flood_fill(game, player->pos_x, player->pos_y);
	if (game->player_found != 1)
		send_exit_game(game, player);
	if (game->exit_found != 1)
		send_exit_game(game, player);
	if (game->coin_found != game->total_coin || game->total_coin == 0)
		send_exit_game(game, player);
	free_copy(game);
}
