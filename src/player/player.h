/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberenge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 05:13:39 by aberenge          #+#    #+#             */
/*   Updated: 2024/12/06 15:56:24 by aberenge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "../../main.h"

typedef struct s_player
{
	int		pos_x;
	int		pos_y;
	void	*skin;
	int		coins;
	int		movement_count;
}	t_player;

typedef struct s_player_movement_params
{
	t_game		*game;
	t_player	*player;
}	t_player_movement_params;

typedef struct s_player_perform
{
	int	new_x;
	int	new_y;
}	t_player_perform;

void	init_player(t_game *game, t_player *player);
int		handle_player_movement(int key, t_player_movement_params *params);
void	locate_player(t_game *game, t_player *player);

#endif
