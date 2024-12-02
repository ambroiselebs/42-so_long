/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberenge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:27:19 by aberenge          #+#    #+#             */
/*   Updated: 2024/12/02 13:35:12 by aberenge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	char	**map;
	char	**map_copy;
	void	*ground_sprite;
	void	*wall_sprite;
	void	*coin_sprite;
	void	*exit_sprite;
	int		total_coin;
	int		win_height;
	int		win_width;
	int		tile_size;
	int		coin_found;
	int		exit_found;
	int		player_found;
}	t_game;

#endif
