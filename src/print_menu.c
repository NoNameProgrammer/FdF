/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_menu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasajj <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 13:28:21 by sasajj            #+#    #+#             */
/*   Updated: 2020/02/23 13:28:22 by sasajj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	print_menu(t_fdf *data)
{
	char *menu;

	menu = "up, down, left, right: move image";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 5, 0xFF00FF, menu);
	menu = "5 : 3d/2d mode; +, -: zoom";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 20, 0xFF00FF, menu);
	menu = "8, 2: z-scale; 4, 6 : rotate";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 35, 0xFF00FF, menu);
}
