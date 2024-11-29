/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberenge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:01:06 by aberenge          #+#    #+#             */
/*   Updated: 2024/11/23 14:47:06 by aberenge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "../exit_game/exit.h"
#include "ft_printf.h"

void	exit_error(t_game *game, t_player *player, char *msg)
{
	t_exit_game_params	params;

	params.game = game;
	params.player = player;
	ft_printf("Error\n%s\n", msg);
	exit_game(&params);
}
