/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberenge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:27:19 by aberenge          #+#    #+#             */
/*   Updated: 2024/11/15 06:03:32 by aberenge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	char	**map;
	void	*ground_sprite;
	void	*wall_sprite;
	int		total_coin;
	int		win_height;
	int		win_width;
	int		tile_size;
}	t_game;

#endif
