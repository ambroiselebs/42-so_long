/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberenge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 03:44:55 by aberenge          #+#    #+#             */
/*   Updated: 2024/12/02 13:35:43 by aberenge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "../../main.h"
# include "../player/player.h"

typedef struct s_put_texture_params
{
	t_game		*game;
	t_player	*player;
}	t_put_texture_params;

int		open_map(char *map_path);
void	init_map(char *map_path, t_game *game);
void	draw_map(t_game *game, t_player *player);
void	check_map_pattern(t_game *game, t_player *player);
void	exit_error(t_game *game, t_player *player, char *msg);
void	check_path(t_game *game, t_player *player);

#endif
