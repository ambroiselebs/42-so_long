/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberenge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 19:10:12 by aberenge          #+#    #+#             */
/*   Updated: 2024/11/15 06:39:57 by aberenge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXIT_H
# define EXIT_H

# include "../../main.h"
# include "../player/player.h"

typedef struct s_exit_game_params
{
	t_game		*game;
	t_player	*player;
}	t_exit_game_params;

int	exit_game(t_exit_game_params *params);

#endif
