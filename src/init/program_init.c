/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberenge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 02:11:20 by aberenge          #+#    #+#             */
/*   Updated: 2024/12/05 16:37:58 by aberenge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "libft.h"
#include "ft_printf.h"
#include <stdlib.h>

void	check_args(int argc)
{
	if (argc != 2)
	{
		ft_printf("Error\nInvalid params map required\n");
		exit(0);
	}
}
