/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_gesture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberenge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 06:18:44 by aberenge          #+#    #+#             */
/*   Updated: 2024/11/15 06:42:47 by aberenge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include "ft_printf.h"
#include "../exit_game/exit.h"

int	handle_player_movement(int key, t_player_movement_params *params)
{
	t_exit_game_params	exit_params;

	if (key == 65307)
	{
		exit_params.game = params->game;
		exit_params.player = params->player;
		exit_game(&exit_params);
	}
	return (0);
}
