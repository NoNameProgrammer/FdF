/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasajj <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 13:53:45 by sasajj            #+#    #+#             */
/*   Updated: 2020/02/23 13:53:46 by sasajj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

float	ft_module(float x)
{
	return (x < 0) ? -x : x;
}

float	ft_max(float x, float y)
{
	return (x < y) ? y : x;
}

void	draw_bresenham(t_fdf a, t_fdf b, t_fdf *data)
{
	float	x_step;
	float	y_step;
	float	max;
	int		color;

	set_param(&a, &b, data);
	x_step = b.x - a.x;
	y_step = b.y - a.y;
	max = ft_max(ft_module(x_step), ft_module(y_step));
	x_step /= max;
	y_step /= max;
	color = (b.z || a.z) ? 0x3ADF00 : 0xBBFAFF;
	color = (b.z != a.z) ? 0x21610B : color;
	while ((int)(a.x - b.x) || (int)(a.y - b.y))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, a.x, a.y, color);
		a.x += x_step;
		a.y += y_step;
		if (a.y < 0 || a.x < 0)
			break ;
	}
}

void	draw(t_fdf **data)
{
	int		y;
	int		x;

	y = 0;
	while (data[y])
	{
		x = 0;
		while (1)
		{
			if (data[y + 1])
				draw_bresenham(data[y][x], data[y + 1][x], &data[0][0]);
			if (!data[y][x].is_last)
				draw_bresenham(data[y][x], data[y][x + 1], &data[0][0]);
			if (data[y][x].is_last)
				break ;
			x++;
		}
		y++;
	}
}
