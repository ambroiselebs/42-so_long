/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberenge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 02:11:20 by aberenge          #+#    #+#             */
/*   Updated: 2024/11/15 04:44:20 by aberenge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "libft.h"
#include "ft_printf.h"
#include <stdlib.h>

void	check_ext(char *ext)
{
	if (ft_strlen(ext) < 4 || ft_strlen(ext) > 4)
	{
		ft_printf("Error\nInvalid map extension (should be .ber)\n");
		exit(0);
	}
	if (ft_strncmp(ext, ".ber", 4) != 0)
	{
		ft_printf("Error\nInvalid map extension (should be .ber)\n");
		exit(0);
	}
}

void	check_args(int argc, char **argv)
{
	char	*ext;

	if (argc != 2)
	{
		ft_printf("Error\nInvalid params map required\n");
		exit(0);
	}
	ext = ft_strchr(argv[1], '.');
	check_ext(ext);
}
