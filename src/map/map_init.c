/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberenge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 03:45:22 by aberenge          #+#    #+#             */
/*   Updated: 2024/11/17 01:47:53 by aberenge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "../../includes/gnl/get_next_line.h"
#include "ft_printf.h"
#include "libft.h"
#include <fcntl.h>
#include <stdlib.h>

int	get_map_height(char *map_path)
{
	int		fd;
	int		res;
	char	*line;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\nOpening file error");
		exit(0);
	}
	res = 0;
	line = get_next_line(fd);
	while (line)
	{
		res++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (res);
}

int	open_map(char *map_path)
{
	int	fd;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\nOpening file error");
		exit(0);
	}
	return (fd);
}

void	null_map_error(void)
{
	ft_printf("Error\nMemory allocation failed\n");
	exit(0);
}

void	set_game_value(int map_width, int map_height, t_game *game)
{
	game->win_width = map_width;
	game->win_height = map_height;
}

void	init_map(char *map_path, t_game *game)
{
	int		fd;
	char	*line;
	char	**map;
	int		i;

	map = malloc(sizeof(char *) * (get_map_height(map_path) + 1));
	if (!map)
		null_map_error();
	fd = open_map(map_path);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (line)
		{
			map[i++] = ft_strtrim(line, "\n");
			free(line);
		}
		line = get_next_line(fd);
	}
	map[i] = NULL;
	close(fd);
	game->map = map;
	set_game_value(ft_strlen(map[0]), get_map_height(map_path), game);
}
