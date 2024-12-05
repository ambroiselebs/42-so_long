/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberenge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 19:10:12 by aberenge          #+#    #+#             */
/*   Updated: 2024/12/05 16:33:22 by aberenge         ###   ########.fr       */
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
	int			error;
}	t_exit_game_params;

int		exit_game(t_exit_game_params *params);
void	free_copy(t_game *game);
void	exit_error(t_game *game, t_player *player, char *msg);

#endif
