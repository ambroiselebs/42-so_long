/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberenge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:37:35 by aberenge          #+#    #+#             */
/*   Updated: 2024/12/06 16:05:03 by aberenge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "../../main.h"
#include "../exit_game/exit.h"
#include "ft_printf.h"
#include "libft.h"

void	check_rectangular(t_game *game, t_player *player)
{
	int i;
	int width;

	if (!game->map || !game->map[0])
		exit_error(game, player, "Invalid map: map is empty");

	width = ft_strlen(game->map[0]);
	i = 0;
	while (game->map[i])
	{
		if ((int)ft_strlen(game->map[i]) != width)
			exit_error(game, player, "Invalid map: map is not rectangular");
		i++;
	}
	game->win_width = width;
	game->win_height = i;
}

void	check_closed(t_game *game, t_player *player)
{
	int	i;

	i = 0;
	while (game->map[0][i])
	{
		if (game->map[0][i] != '1')
			exit_error(game, player, "Map not closed");
		i++;
	}
	i = 0;
	while (game->map[game->win_height - 1][i])
	{
		if (game->map[game->win_height - 1][i] != '1')
			exit_error(game, player, "Map not closed");
		i++;
	}
	i = 0;
	while (i < game->win_height)
	{
		if (game->map[i][0] != '1' || game->map[i][game->win_width - 1] != '1')
			exit_error(game, player, "Map not closed");
		i++;
	}
}

void	check_map_pattern(t_game *game, t_player *player)
{
	check_rectangular(game, player);
	check_closed(game, player);
}
